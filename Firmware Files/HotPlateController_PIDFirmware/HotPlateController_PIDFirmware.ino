////# # # # # # # # # # # # # # # # # # # # # # # # # #
//// Chandler McCowan
//// Hot Plate Controller Test Firmware
//// Created February 02 2021
//// For ESP32 Module
////# # # # # # # # # # # # # # # # # # # # # # # # # #

// Serial Comm Definitions
#define BAUD_RATE 115200

// Libraries
#include <SPI.h>
#include "Adafruit_MAX31855.h"
#include <PID_v1.h>


#define THERMO_DO 19          // SPI Comms Digital Output
#define THERMO_CS 23          // SPI Comms Chip Select
#define THERMO_CLK 5          // SPI Comms Clock Signals

// initialize the Thermocouple
Adafruit_MAX31855 thermocouple(THERMO_CLK, THERMO_CS, THERMO_DO);

void setup(){
  Serial.begin(115200);
  Serial.println("Start of Sketch");

  setup_pins();

  
}

void loop(){
  
}
