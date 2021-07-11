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

  WiFiProvision();
  
}


 
void loop() {
  // put your main code here, to run repeatedly:

}
