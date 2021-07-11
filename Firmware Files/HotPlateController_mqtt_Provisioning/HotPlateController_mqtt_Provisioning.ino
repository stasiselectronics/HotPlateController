// this code is to show how to provision an ESP32 onto a wifi network
// use it to easily flash code and configure the device over serial

// This code is built around the Stasis Electronics Hot Plate Controller
// an esp32 controller for SMD reflow



                                            
// Starting off with libraries to include
// TODO: add information on how to install new libriaries

#include <WiFi.h>
#include <PubSubClient.h>
#include <EEPROM.h>

// Settings
#define EEPROM_SIZE 512 // total memory in bytes we can save and read
#define BAUD_RATE 115200 // for serial communication
#define BUFFSIZE 64 // size of a common char array buffer size
#define TOTAL_MEMORY 512
#define RESPONSE_TIMEOUT 60000 // one minute in ms

// Global Objects
WiFiClient myWiFiClient;
PubSubClient client(myWiFiClient);
unsigned int stack_pointer = 0;
char msg_buffer[TOTAL_MEMORY];
char mySSID[BUFFSIZE];
char myPassword[BUFFSIZE];

String readstring(unsigned int timeout){
  char message_buffer[BUFFSIZE] = "Uninitialized";
  memset(message_buffer, '\0', BUFFSIZE);
  unsigned int start_time = millis();
  bool done = false;
  unsigned int counter = 0;
  while(!done){
    if(Serial.available()){
      message_buffer[counter]=Serial.read();
      if(message_buffer[counter] == '\n'){
        done = true;
        message_buffer[counter] = '\0';
        // replace line feed with null terminating
      }
      counter++;
    }
    if(counter>BUFFSIZE){
      counter=0;
      memset(message_buffer, '\0', BUFFSIZE); // clear the buffer
    }
    if(millis() - start_time > timeout){
      done = true;
      memset(message_buffer, '\0', BUFFSIZE); // clear the buffer
      strcpy(message_buffer, "Timeout");
    }
  }
  String myresponse = (String) message_buffer;
  return myresponse;
}

unsigned int readNetworkInfo(){
  unsigned int checksum = 0;
  for(int i = 0; i < 64; i++){
    mySSID[i]=(char)EEPROM.read(i);
    myPassword[i]=(char)EEPROM.read(i+64);
    checksum+=(byte)mySSID[i] + (byte)myPassword[i];
  }
  return checksum;
}

unsigned int saveNetworkInfo(){
  unsigned int checksum = 0;
  for(int i = 0; i < 64; i++){
    EEPROM.write(i, mySSID[i]);
    EEPROM.write(i+64, myPassword[i]);
    checksum+=(byte)mySSID[i] + (byte)myPassword[i];
  }
  EEPROM.commit();
  return checksum;
}

void setup() {
  // put your setup code here, to run once:
  String  TitleCard  = ("======================================================\n");
          TitleCard += ("===  ESP32 WiFi Serial Provision        ==============\n");
          TitleCard += ("===  Start of Sketch                    ==============\n");
          TitleCard += ("======================================================\n");

  // Setup Comm links
  Serial.begin(BAUD_RATE);
  Serial.print(TitleCard);
  Serial.println(" . . . . . . . . . . . . .\nBeginning Initialization\n\n");

  // Setup Memory
  EEPROM.begin(EEPROM_SIZE);

  Serial.println("Checking for existing network credentials");
  if(readNetworkInfo()){
    // there are existing crednetials, lets try those 
    Serial.println("Credentials found:");
    Serial.println(mySSID);
    Serial.println(myPassword); 
    Serial.print("Checksum:  ");Serial.println(readNetworkInfo());
    Serial.println("Let's try connecting to that one");
  }
  else{
    Serial.println("Going to go check what WiFi Networks are there...\n");
    int number_of_networks = WiFi.scanNetworks();
    if (number_of_networks == 0) {
      Serial.println("Oh dear! No networks found...");
      // TODO: add error handling
    }
    else{
      Serial.println("There are " + (String) number_of_networks + " networks available to connect to");
      Serial.flush();
      delay(10);
      for (int i = 0; i < number_of_networks; ++i) {
        // Print SSID and RSSI for each network found
        Serial.print(i+1); Serial.print(" : ");
        String mySSID = WiFi.SSID(i);
        Serial.print(mySSID);
        Serial.print('\n');
        Serial.flush();
        delay(3);
      }
      // ask which one to connect to
      Serial.println("What's the SSID you want to connect to? Enter its number and press enter");
      Serial.println("If nothing happens, make sure you are appending a line feed to your input");
      String response = readstring(RESPONSE_TIMEOUT);
      if(response == "Timeout"){
        Serial.println("Input timeout, restart to try again");
        while(true){
          int i = rand()*100;
        }
      }
      response.toCharArray(mySSID, BUFFSIZE);
      Serial.println("Connecting to " + (String)mySSID);
      Serial.println("What's the password?");
      response = readstring(RESPONSE_TIMEOUT);
      response.toCharArray(myPassword, BUFFSIZE);
    }
  }
  // Either we loaded credentials or we asked for new ones
  // ready to try and connect
  Serial.println("Attempting to connect");
  WiFi.begin((char*)mySSID, (char*)myPassword);
  unsigned long start_time = millis();
  while(WiFi.status() != WL_CONNECTED) {
    unsigned long current_time = millis();
    if(current_time-start_time>=1000) {
      Serial.print("\u2592"); // Print a block ▒
      start_time=current_time;
    }
  }
  Serial.println("\n\nDevice connected successfully!");
  Serial.print("IPv4 Address:  ");Serial.println(WiFi.localIP());
  
  Serial.println("Saving credentials");
  Serial.print("Checksum:  ");Serial.println(saveNetworkInfo());
}


 
void loop() {
  // put your main code here, to run repeatedly:

}
