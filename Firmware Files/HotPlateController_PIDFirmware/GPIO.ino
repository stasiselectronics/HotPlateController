// This file handles setting up and handling the General Purpose Inputs and Outputs

// Pin Mapping - These are specific to the board design, change at your own risk!
#define LED_STATUS 12         // Green LED, active high
#define LED_HEATER 13         // Orange LED, active high
#define CONTROL_HEATER 2      // MOSFET Gate signal, used to turn on and off the solid state relay to control heating element
#define CURRENT_SENSOR 35     // Voltage output of the current sensor, will produce sinusoidal waveform proportional to AC current
#define FIVE_VOLT_RAIL 34     // 5V supply rail divided in half to fit within ESP32's ADC window of 0-3.3V. Expect 2.5V


void setup_pins(){
  // Setup Pins
  Serial.println("** Setting up Pins **");
  Serial.println("Status LED: Pin 14, GPIO 12");
  pinMode(LED_STATUS,         OUTPUT);
  Serial.println("Heater LED: Pin 16, GPIO 13");
  pinMode(LED_HEATER,         OUTPUT);
  Serial.println("Heater Control: Pin 24, GPIO 2");
  pinMode(CONTROL_HEATER,     OUTPUT);
  Serial.println("Current Sensor: Pin 7, GPIO 34");
  pinMode(CURRENT_SENSOR,     OUTPUT);
  Serial.println("5V/2 Supply Sense: Pin 6, GPIO 34");
  pinMode(FIVE_VOLT_RAIL,     INPUT);
  //ledcSetup(2,5000,8);
  //ledcAttachPin(CONTROL_HEATER, 2);
}
