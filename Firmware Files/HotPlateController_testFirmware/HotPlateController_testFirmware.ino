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


void setup() {
  // Serial Communication Init
  Serial.begin(BAUD_RATE);

  Serial.print("* * * *\n* * * *\n* * * *\n* * * *\n"); // Used to clear console from the ESP32's boot output
  Serial.println("======================================================");
  Serial.println("===  Hotplate Controller Test Firmware  ==============");
  Serial.println("===  Start of Sketch                    ==============");
  Serial.println("======================================================");
}

void loop() {
  yield();

}
