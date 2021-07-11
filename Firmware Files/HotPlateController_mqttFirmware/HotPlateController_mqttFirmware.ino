// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
//      Stasis Electronics
//      Hot Plate Controller rev A02
//      ESP32 firmware for control over mqtt
//      This firmware is intended for the A02 PCB revision
//      Open source, feel free to copy, modify, and or distribute
//      No garuntees or warranty, but I try my best to make it work
//      Chandler McCowan, April 11 2021
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

// Libraries
#include <WiFi.h>
#include <SPI.h>
#include <PubSubClient.h>
#include "Adafruit_MAX31855.h"
#include <EEPROM.h>

// Settings
#define EEPROM_SIZE 512 // total memory in bytes we can save and read
#define BAUD_RATE 115200 // for serial communication
#define BUFFSIZE 64 // size of a common char array buffer size
#define TOTAL_MEMORY 512
#define RESPONSE_TIMEOUT 60000 // one minute in ms

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

// Network Details
char mySSID[BUFFSIZE];
char myPassword[BUFFSIZE];
char myMQTTServer[BUFFSIZE];

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


double hotPlateTemperature = 0;
extern volatile bool LED_blink_enable;

// Global Memory Locations
#define WIFI_SSID_ADDR 0
#define WIFI_PASSWORD_ADDR 64 // not the most secure, but oh well
#define MQTT_SERVER_ADDR 128
#define CUTOFFTEMPERATURE_ADDR 192

// Message buffers to make sure data types play nice with each other
#define BUFFER_SIZE 512
char msg_buffer[BUFFER_SIZE];



void setup() {
  
  setup_timers();
    
                       // Title Card
  String  TitleCard  = ("======================================================\n");
          TitleCard += ("===  Hotplate Controller MQTT Firmware  ==============\n");
          TitleCard += ("===  Start of Sketch                    ==============\n");
          TitleCard += ("======================================================\n");

  // Setup Comm links
  Serial.begin(BAUD_RATE);
  Serial.print(TitleCard);
  Serial.println(" . . . . . . . . . . . . .\nBeginning Initialization");

  // Setup Pins
  setup_pins();

  // Setup Sensors
  setup_sensors();

  // Setup Memory
  EEPROM.begin(EEPROM_SIZE);
  cutoffTemperature = EEPROM.read(CUTOFFTEMPERATURE_ADDR);
  if(cutoffTemperature > 250 || cutoffTemperature < 25){
    EEPROM.write(CUTOFFTEMPERATURE_ADDR, 25);
    EEPROM.commit();
  }
  Serial.print("Read Cutoff Temp from memory:");Serial.println(cutoffTemperature);

  LED_blink_enable = true;
  WiFiProvision();
  

  
  // We are now connected to the WiFi network

  mqtt_refreshConnection();
  
  // We should now be connected to the MQTT Broker
  if(client.connected()){
    Serial.println("");
    Serial.println("MQTT connected successfully");
    LED_blink_enable = false;
    digitalWrite(LED_STATUS, HIGH);
    digitalWrite(LED_HEATER, LOW);
  }
  else {
    Serial.println("Failed to connect!");
    Serial.println("Restarting");
    delay(2000);
    ESP.restart();
  }
  
  
}

void loop() {
  unsigned long current_time = millis();
  static unsigned long timer_1 = current_time;
  static unsigned long timer_2 = current_time;
  static bool run_once = true;
  if(run_once){
    Serial.println((String)"\n . . . . . . . . . . . . .\n"+"Entered Loop");
    run_once = false;
  }
  
  if(!client.connected()){
    mqtt_refreshConnection();
  }
  if(current_time - timer_2 > 50){
    timer_2 = current_time;
    // Actions every 50 ms
    hotPlateTemperature = thermocouple.readCelsius();
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
    
    Serial.print(myRSSI);Serial.print(",");
    Serial.print(myTemp);Serial.print(",");
    Serial.print(myStatus);Serial.print(",");
    Serial.println(myCutoff);
    
  }
  client.loop(); //process any new messages and trigger any callbacks
  yield(); // To keep the board running and feed watchdogs
}
