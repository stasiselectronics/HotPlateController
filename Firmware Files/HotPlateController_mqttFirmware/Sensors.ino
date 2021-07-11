// Code to get the sensors working

void setup_sensors(){
  // Setup thermocouple
  if (!thermocouple.begin()) {
    Serial.println("Failed to initialize thermocouple");
  }
  else{
    Serial.println("Thermocouple initalized");
    Serial.print("Current Temperature: ");Serial.print(thermocouple.readCelsius());
    Serial.println(" deg C");
  }
  Serial.println("Checking current sensor");
  Serial.print("Raw ADC: ");Serial.println(analogRead(CURRENT_SENSOR));
  Serial.print("5V ADC: ");Serial.println(analogRead(FIVE_VOLT_RAIL));
}
