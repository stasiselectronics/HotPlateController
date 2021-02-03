////# # # # # # # # # # # # # # # # # # # # # # # # # #
//// Chandler McCowan
//// Hot Plate Controller Test Firmware
//// Created February 02 2021
//// For ESP32 Module
////# # # # # # # # # # # # # # # # # # # # # # # # # #

// Serial Comm Definitions
#define BAUD_RATE 115200

// Libraries
#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include <LITTLEFS.h>
#include <ArduinoJson.h>
#include <AsyncJson.h>

// Pin Definitions
#define LED_STATUS 13
#define LED_HEATER 17
#define CONTROL_HEATER 2
#define CURRENT_SENSOR 35

// WiFi Credentials
const char* ssid = "comhem_56E137";
const char* password =  "9zpht1au";

// Start webserver on normal HTTP port 80
AsyncWebServer server(80);

// If we cannot mount the LittleFS disk, shall we format one?
#define FORMAT_LITTLEFS_IF_FAILED false

void setup() {
  // Serial Communication Init
  Serial.begin(BAUD_RATE);
  Serial.println("======================================================");
  Serial.println("===  Hotplate Controller Test Firmware  ==============");
  Serial.println("===  Start of Sketch                    ==============");
  Serial.println("======================================================");

  // Pin Initialization
  pinMode(LED_STATUS,     OUTPUT);
  pinMode(LED_HEATER,     OUTPUT);
  pinMode(CONTROL_HEATER, OUTPUT);
  pinMode(CURRENT_SENSOR, INPUT );


  // Web Server Initialization
  Serial.println("Mounting LittleFS Filesystem");
  if (!LITTLEFS.begin(FORMAT_LITTLEFS_IF_FAILED)) {
    Serial.println("LITTLEFS Mount failed!");
    Serial.println("Check to see if you uploaded the files using LittleFS and not SPIFFS.");
    Serial.println("Aborting startup");
    while(true){
      int i = 1 + rand();
    }
  } else {
    Serial.println("LITTLEFS Mount successful.");
    Serial.println("Files found:");
    listDir(LITTLEFS, "/", 2);
  }

  // Begin WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ");
  static unsigned long start_time = millis();
  while(WiFi.status() != WL_CONNECTED) {
    unsigned long current_time = millis();
    if(current_time-start_time>=1000)
    {
      Serial.print(".");
      start_time=current_time;
    }
  }

  Serial.print("/n/n");
  Serial.println("Device successfully connected");
  Serial.print("IPv4 Address:");Serial.println(WiFi.localIP());

  
}

void loop() {
  yield();
  delay(850);
  digitalWrite(LED_STATUS, !digitalRead(LED_STATUS));
  digitalWrite(LED_HEATER, !digitalRead(LED_HEATER));

}

// Stolen from the example sketch on how to list files in a dir
void listDir(fs::FS &fs, const char * dirname, uint8_t levels) {
  Serial.printf("Listing directory: %s\r\n", dirname);

  File root = fs.open(dirname);
  if (!root) {
    Serial.println("- failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println(" - not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if (levels) {
        listDir(fs, file.name(), levels - 1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("\tSIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
}
