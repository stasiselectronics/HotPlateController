// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
//      Stasis Electronics
//      Hot Plate Controller rev A02
//      ESP32 firmware for control over mqtt
//      This firmware is intended for the A02 PCB revision
//      Open source, feel free to copy, modify, and or distribute
//      No garuntees or warranty, but I try my best to make it work
//      Chandler McCowan, April 11 2021
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

// Serial Comm Definitions
#define BAUD_RATE 115200
#define ENABLE_DEBUG_OUTPUT //comment out to disable debug output

// Copy and paste this around debug output to add enable/disable control

#ifdef ENABLE_DEBUG_OUTPUT
// Debug Output Code 
#endif

// Libraries
#include <WiFi.h>
#include <SPI.h>
#include <PubSubClient.h>
#include "Adafruit_MAX31855.h"
#include <EEPROM.h>


// Network Details - Change these to match your own network!
const char* ssid = "comhem_56E137";
const char* password =  "9zpht1au";
const char* mqtt_server = "192.168.0.7";

const char* mqtt_clientID = "Hot Plate";
const char* mqtt_Tag = "Lab/HotPlate/";


// Pin Mapping - These are specific to the board design, change at your own risk!
#define LED_STATUS 12         // Green LED, active high
#define LED_HEATER 13         // Orange LED, active high
#define CONTROL_HEATER 2      // MOSFET Gate signal, used to turn on and off the solid state relay to control heating element
#define CURRENT_SENSOR 35     // Voltage output of the current sensor, will produce sinusoidal waveform proportional to AC current
#define FIVE_VOLT_RAIL 34     // 5V supply rail divided in half to fit within ESP32's ADC window of 0-3.3V. Expect 2.5V
#define THERMO_DO 19
#define THERMO_CS 23
#define THERMO_CLK 5

// Memory Settings
#define EEPROM_SIZE 256

// Function Calls
// Place here to help the compiler know where to look for extra functions
void mqtt_refreshConnection();
void mqtt_parse_message(char* topic, byte* message, unsigned int length);

// Global Objects
// These help get things going
WiFiClient myWiFiClient;
PubSubClient client(myWiFiClient);
Adafruit_MAX31855 thermocouple(THERMO_CLK, THERMO_CS, THERMO_DO);
volatile int cutoffTemperature = 25;
int cutoffTemperature_ADDR = 0;
volatile int interuptCounter;
int totalInterruptCounter;
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;


// Message buffers to make sure data types play nice with each other
#define BUFFER_SIZE 512
char msg_buffer[BUFFER_SIZE];

volatile int LED_blink_timer = 0;
volatile int LED_blink_period = 200;
volatile bool LED_blink_enable = false;

// Interrupt Service Routine that should be called every ms
void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  if(LED_blink_enable){
    if(LED_blink_timer > LED_blink_period){
      // Toggle LED
      LED_blink_timer = 0;
      digitalWrite(LED_STATUS,!digitalRead(LED_STATUS));
    }
    else{
      LED_blink_timer++;
    }
  }
  portEXIT_CRITICAL_ISR(&timerMux);
 
}

void setup() {

  // Setup Timers
  timer =timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000, true);
  timerAlarmEnable(timer);
  
  // Title Card
  #ifdef ENABLE_DEBUG_OUTPUT
  String  TitleCard  = ("======================================================\n");
          TitleCard += ("===  Hotplate Controller MQTT Firmware  ==============\n");
          TitleCard += ("===  Start of Sketch                    ==============\n");
          TitleCard += ("======================================================\n");

  // Setup Comm links
  Serial.begin(BAUD_RATE);
  Serial.print(TitleCard);
  Serial.println(" . . . . . . . . . . . . .\nBeginning Initialization");
  #endif

  // Setup Pins
  #ifdef ENABLE_DEBUG_OUTPUT
  Serial.println("** Setting up Pins **");
  Serial.println("Status LED: Pin 14, GPIO 12");
  #endif
  pinMode(LED_STATUS,     OUTPUT);
  
  #ifdef ENABLE_DEBUG_OUTPUT
  Serial.println("Heater LED: Pin 16, GPIO 13");
  #endif
  pinMode(LED_HEATER,     OUTPUT);
  
  #ifdef ENABLE_DEBUG_OUTPUT
  Serial.println("Heater Control: Pin 24, GPIO 2");
  #endif
  pinMode(CONTROL_HEATER,     OUTPUT);
  
  #ifdef ENABLE_DEBUG_OUTPUT
  Serial.println("Current Sensor: Pin 7, GPIO 34");
  #endif
  pinMode(CURRENT_SENSOR,     OUTPUT);

  #ifdef ENABLE_DEBUG_OUTPUT
  Serial.println("5V/2 Supply Sense: Pin 6, GPIO 34");
  Serial.println("");
  #endif
  pinMode(FIVE_VOLT_RAIL,     OUTPUT);

  // Setup thermocouple
  if (!thermocouple.begin()) {
    #ifdef ENABLE_DEBUG_OUTPUT
    Serial.println("Failed to initialize thermocouple");
    #endif
  }

  // Setup Memory
  EEPROM.begin(EEPROM_SIZE);
  cutoffTemperature = EEPROM.read(cutoffTemperature_ADDR);
  
  // Setup WiFi
  #ifdef ENABLE_DEBUG_OUTPUT
  Serial.println("** Starting WiFi Initialization **");
  Serial.println((String)"Connecting to "+ssid);
  #endif
  
  LED_blink_enable = true;
  WiFi.begin(ssid, password);

  unsigned long start_time = millis();
  while(WiFi.status() != WL_CONNECTED) {
    unsigned long current_time = millis();
    if(current_time-start_time>=1000) {
      #ifdef ENABLE_DEBUG_OUTPUT
      Serial.print(".");
      start_time=current_time;
      #endif
    }
  }
  
  // We are now connected to the WiFi network
  LED_blink_enable = false;
  digitalWrite(LED_STATUS, HIGH);
  digitalWrite(LED_HEATER, LOW);
  #ifdef ENABLE_DEBUG_OUTPUT
  Serial.print("\n\n");
  Serial.println("Device connected successfully");
  Serial.print("IPv4 Address:  ");Serial.println(WiFi.localIP());
  #endif

  mqtt_refreshConnection();
  
  // We should now be connected to the MQTT Broker
  #ifdef ENABLE_DEBUG_OUTPUT
  if(client.connected()){
  Serial.println("");
  Serial.println("MQTT connected successfully");
  }
  else {
    Serial.println("Failed to connect!");
  }
  #endif
  
}

void loop() {
  unsigned long current_time = millis();
  static unsigned long timer_1 = current_time;
  #ifdef ENABLE_DEBUG_OUTPUT
  static bool run_once = true;
  if(run_once){
    Serial.println((String)"\n . . . . . . . . . . . . .\n"+"Entered Loop");
    run_once = false;
  }
  #endif
  
  if(!client.connected()){
    mqtt_refreshConnection();
  }
   
  if(current_time - timer_1 > 1000){
    timer_1 = current_time;
    // Actions every 1 second
    String myRSSI = (String) WiFi.RSSI();
    myRSSI.toCharArray(msg_buffer, BUFFER_SIZE);
    client.publish("Lab/HotPlate/RSSI", msg_buffer);

    String myTemp = (String) thermocouple.readCelsius();
    myTemp.toCharArray(msg_buffer, BUFFER_SIZE);
    client.publish("Lab/HotPlate/Temperature", msg_buffer);

 
    String myStatus = digitalRead(CONTROL_HEATER) ? "true":"false";
    myStatus.toCharArray(msg_buffer, BUFFER_SIZE);
    client.publish("Lab/HotPlate/HeaterStatus", msg_buffer);

    String myCutoff = (String) cutoffTemperature;
    myCutoff.toCharArray(msg_buffer, BUFFER_SIZE);
    client.publish("Lab/HotPlate/CutOff", msg_buffer);
    
    #ifdef DISABLE_DEBUG_OUTPUT
    Serial.println("** Values Sent **");
    Serial.print("RSSI: ");Serial.println(myRSSI);
    Serial.print("Temperature: ");Serial.println(myTemp);
    Serial.print("Heater status: ");Serial.println(myStatus);
    Serial.print("Cut Off Temp: ");Serial.println(myCutoff);
    #endif
    
  }
  client.loop(); //process any new messages and trigger any callbacks
  yield(); // To keep the board running and feed watchdogs
}

void mqtt_refreshConnection(){
  // Connect to MQTT Server
  #ifdef ENABLE_DEBUG_OUTPUT
  Serial.println("** Initializing MQTT **");
  Serial.println((String)"Connecting to "+mqtt_server);
  #endif

  client.setServer(mqtt_server, 1883);
  client.connect(mqtt_clientID);
  client.setCallback(mqtt_parse_message);
  client.subscribe("Lab/HotPlate/#");
  
  long start_time = millis();
  bool done_flag = false;
  while(!client.connected() && !done_flag) {
    unsigned long current_time = millis();
    if(current_time-start_time>=150)
    {
      #ifdef ENABLE_DEBUG_OUTPUT
      Serial.print(".");
      #endif
      start_time=current_time;
      if(current_time-start_time>=10000){
        done_flag = true;
        break;
      }
    }
  }
}

void mqtt_parse_message(char* topic, byte* message, unsigned int length) {
  String messageTemp;
  for (int i = 0; i < length; i++) {
    messageTemp += (char)message[i];
  }
  if (String(topic) == "Lab/HotPlate/SetStatus") {
    Serial.print("Changing output to ");
    if(messageTemp == "true"){
      Serial.println("on");
      digitalWrite(CONTROL_HEATER, HIGH);
      digitalWrite(LED_HEATER, HIGH);
    }
    else if(messageTemp == "false"){
      Serial.println("off");
      digitalWrite(CONTROL_HEATER, LOW);
      digitalWrite(LED_HEATER, LOW);
    }
  }
  if (String(topic) == "Lab/HotPlate/SetCufOff") {
    Serial.print("Changing output to ");
    cutoffTemperature = messageTemp.toInt();
    Serial.println(messageTemp);
  }
}
