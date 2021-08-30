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



// Pin Mapping - These are specific to the board design, change at your own risk!
#define LED_STATUS 12         // Green LED, active high
#define LED_HEATER 13         // Orange LED, active high
#define CONTROL_HEATER 2      // MOSFET Gate signal, used to turn on and off the solid state relay to control heating element
#define CURRENT_SENSOR 35     // Voltage output of the current sensor, will produce sinusoidal waveform proportional to AC current
#define FIVE_VOLT_RAIL 34     // 5V supply rail divided in half to fit within ESP32's ADC window of 0-3.3V. Expect 2.5V

#define THERMO_DO 19          // SPI Comms Digital Output
#define THERMO_CS 23          // SPI Comms Chip Select
#define THERMO_CLK 5          // SPI Comms Clock Signals

// initialize the Thermocouple
Adafruit_MAX31855 thermocouple(THERMO_CLK, THERMO_CS, THERMO_DO);
extern volatile double thermocoupleTemperature;
extern volatile bool LED_blink_enable;

// PID settings
//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,20,2,0.1, DIRECT);

void set_dutycycle(double input);

void setup(){
  Serial.begin(115200);
  Serial.println("Start of Sketch");

  setup_pins();
  setup_timers();

  Serial.println("MAX31855 test");
  // wait for MAX chip to stabilize
  delay(500);
  Serial.print("Initializing sensor...");
  if (!thermocouple.begin()) {
    Serial.println("ERROR.");
    while (1) delay(10);
  }
  Serial.println("DONE.");

  Setpoint = 200;
  myPID.SetMode(AUTOMATIC);
  //digitalWrite(CONTROL_HEATER, HIGH);
  set_dutycycle(0.5);
  digitalWrite(LED_STATUS, HIGH);
  test_run_control();
}

void loop(){
  delay(100);
  Serial.print(Setpoint);Serial.print(",");
  Serial.print(thermocoupleTemperature);Serial.print(",");
  Input = thermocoupleTemperature;
  myPID.Compute();
  if(0.9 * thermocoupleTemperature > Setpoint){
    Output = 0;
  }
  set_dutycycle(Output/255.0);
  Serial.println((Output/255.0)*Setpoint);
}

void test_run(){
  
  unsigned int startTime = millis();
  // this should ramp up to 100 degrees and then cool off
  set_dutycycle(1);
  //digitalWrite(CONTROL_HEATER, HIGH); // turn on the heater
  Serial.println("Starting Test");
  while(thermocoupleTemperature < Setpoint){ // while it is less than the setpoint
    delay(100);
    Serial.print((millis()-startTime)/1000.0); Serial.print(",");
    Serial.println(thermocoupleTemperature);
  }
  //digitalWrite(CONTROL_HEATER, LOW);
  set_dutycycle(0.1);
  Serial.println("Set Heater to 10%");
  while(true){
    delay(100);
    Serial.print((millis()-startTime)/1000.0); Serial.print(",");
    Serial.println(thermocoupleTemperature);
  }
}

void test_run_control(){
  unsigned int startTime = millis();
  double temperature_derrivative = 0;
  double previous_temperature = thermocoupleTemperature;
  unsigned int seconds_timer = millis();
  
  // Start of with ramping up to to the set point, but only to 80% of the setpoint to compensate for overshoot
  set_dutycycle(1.0);
  LED_blink_enable = true;
  // wait until we get to 80% of the set point
  while(thermocoupleTemperature < (Setpoint*(1.0 - 0.2))){
    if(millis()-seconds_timer > 1000){
      temperature_derrivative = (thermocoupleTemperature - previous_temperature);
      previous_temperature = thermocoupleTemperature;
      seconds_timer = millis();
    }
    Serial.print((millis()-startTime)/1000.0);Serial.print(",");Serial.print(thermocoupleTemperature); Serial.print(",");Serial.println(temperature_derrivative);
    delay(100);
  }
  // Now we are performing the overshoot, so we should cut power
  set_dutycycle(0.0);
  // we should keep track of when we get to the appogee of the temperature
  
  while(true){
    if(millis()-seconds_timer > 1000){
      temperature_derrivative = (thermocoupleTemperature - previous_temperature);
      previous_temperature = thermocoupleTemperature;
      seconds_timer = millis();
    }
    if(temperature_derrivative < 0.0){
      break; // break out of the while loop once we start dropping
    }
    Serial.print((millis()-startTime)/1000.0);Serial.print(",");Serial.print(thermocoupleTemperature); Serial.print(",");Serial.println(temperature_derrivative);
    delay(100);
  }
  while(true){
    double dutycycle = 0;
    // now we can try and do some P control

    if(abs(Setpoint-thermocoupleTemperature)< 5){
      LED_blink_enable = false;
      digitalWrite(LED_HEATER, HIGH);
    }
    else{
      LED_blink_enable = true;
      digitalWrite(LED_HEATER, LOW);
    }
    
    if(thermocoupleTemperature>Setpoint){
      // We are higher than the set point and need to cool down
      set_dutycycle(0.0);
    }
    else{
      // We are lower than the set point and need to heat up
      // 50% increase in duty cycle for every degree we are off
      dutycycle = (Setpoint - thermocoupleTemperature)* 0.50;
      set_dutycycle(dutycycle);
    }
    
    Serial.print((millis()-startTime)/1000.0);Serial.print(",");Serial.print(thermocoupleTemperature); Serial.print(",");Serial.println(dutycycle);
    delay(100);

    
  }
}
