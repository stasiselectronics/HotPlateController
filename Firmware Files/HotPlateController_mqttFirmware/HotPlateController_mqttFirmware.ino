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

// Copy and paste this around debug output to add enable/diable control

#ifdef ENABLE_DEBUG_OUTPUT
// Debug Output Code 
#endif

// Libraries
#include <WiFi.h>
#include <SPI.h>
#include <PubSubClient.h>
#include "Adafruit_MAX31855.h"


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

// Function Calls
// Place here to help the compiler know where to look for extra functions
bool setup_wifi();
void mqtt_reconnect();

// Global Objects
// These help get things going
WiFiClient myWiFiClient;
PubSubClient client(myWiFiClient);

// Message buffers to make sure data types play nice with each other
#define BUFFER_SIZE 512
char msg_buffer[BUFFER_SIZE];

// Global Function Names
void mqtt_refreshConnection();


void setup() {
  // Title Card
  #ifdef ENABLE_DEBUG_OUTPUT
  String TitleCard = "Hot Plate Controller\nMQTT Firmware";
  TitleCard  = ("======================================================\n");
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

  // Setup WiFi
  #ifdef ENABLE_DEBUG_OUTPUT
  Serial.println("** Starting WiFi Initialization **");
  Serial.println((String)"Connecting to "+ssid);
  #endif

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
