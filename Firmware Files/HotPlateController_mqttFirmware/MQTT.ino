

void mqtt_refreshConnection(){
  // Connect to MQTT Server
  Serial.println("** Initializing MQTT **");
  Serial.print("Connecting to ");
  Serial.println(myMQTTServer);

  client.setServer(myMQTTServer, 1883);
  client.connect(mqtt_clientID);
  client.setCallback(mqtt_parse_message);
  client.subscribe("Lab/HotPlate/#");
  
  long start_time = millis();
  bool done_flag = false;
  while(!client.connected() && !done_flag) {
    unsigned long current_time = millis();
    if(current_time-start_time>=150)
    {
      Serial.print(".");
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
    if(cutoffTemperature > 250 || cutoffTemperature < 25){
      cutoffTemperature = 25;
      }
    EEPROM.write(CUTOFFTEMPERATURE_ADDR, cutoffTemperature);
    EEPROM.commit();
    Serial.println(cutoffTemperature);
  }
}
