

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
#include <SPI.h>
#include "ESPAsyncWebServer.h"
#include <LITTLEFS.h>
#include <ArduinoJson.h>
#include "Adafruit_MAX31855.h"
#include <AsyncJson.h>

// Pin Definitions
#define LED_STATUS 12 
#define LED_HEATER 13
#define CONTROL_HEATER 2
#define CURRENT_SENSOR 35
#define FIVEVRAIL 34

int thermoDO = 19;
int thermoCS = 23;
int thermoCLK = 5;

// initialize the Thermocouple
Adafruit_MAX31855 thermocouple(thermoCLK, thermoCS, thermoDO);

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

  // Thermocouple Sensor Initialization
  delay(500);
  Serial.print("Initializing Thermocouple Sensor...");
  if (!thermocouple.begin()) {
    Serial.println("ERROR.");
    while (1) delay(10);
  }
  Serial.println("DONE.\n\n\n");

  // File System Initialization
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
  Serial.println("Starting Wifi");
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
  digitalWrite(CONTROL_HEATER, !digitalRead(CONTROL_HEATER));
  double current_sensor_voltage = analogRead(CURRENT_SENSOR);
  double fiveVRail_voltage = analogRead(FIVEVRAIL);
  current_sensor_voltage = current_sensor_voltage / 4096 * 5;
  fiveVRail_voltage = fiveVRail_voltage / 4096 * 5 * 2;
  Serial.print(current_sensor_voltage);Serial.print(",");
  Serial.print(fiveVRail_voltage);Serial.print(",");
  Serial.print(current_sensor_voltage/fiveVRail_voltage);Serial.print(",");
  //Serial.println((String)thermocouple.readCelsius());
  double c = thermocouple.readCelsius();
  if (!isnan(c)) {
     Serial.println(c);
   }

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
