
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
