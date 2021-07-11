// Variables to allow you to change the blink behavior
volatile int LED_blink_timer = 0;
volatile int LED_blink_period = 200;
volatile bool LED_blink_enable = false;

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;


// Interrupt Service Routine that should be called every ms
void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  if(LED_blink_enable){
    if(LED_blink_timer > LED_blink_period){
      // Toggle LED
      LED_blink_timer = 0;
      digitalWrite(LED_STATUS,!digitalRead(LED_STATUS));
    }
    else{
      LED_blink_timer++;
    }
  }
  if(hotPlateTemperature>cutoffTemperature){
    // turn off the relay
    digitalWrite(CONTROL_HEATER, LOW);
    digitalWrite(LED_HEATER, LOW);
  }
  portEXIT_CRITICAL_ISR(&timerMux);
 
}

void setup_timers(){
  // Setup Timers
  timer =timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000, true);
  timerAlarmEnable(timer);
}
