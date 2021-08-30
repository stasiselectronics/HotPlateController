// Variables to allow you to change the blink behavior
volatile int LED_blink_timer = 0;
volatile int LED_blink_period = 200;
volatile bool LED_blink_enable = false;
volatile int thermocouplePeriod = 200;
volatile int thermocoupleTimer = 0;
volatile int SSRPeriod_on = 0;
volatile int SSRonTimer = 0;
volatile int SSRPeriod_off = 1000;
volatile int SSRoffTimer = 0;
volatile double thermocoupleTemperature = 0;
volatile bool SSRon = false;
volatile bool SSRenabled = true;
extern Adafruit_MAX31855 thermocouple;

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;


// Interrupt Service Routine that should be called every ms
void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  if (LED_blink_enable) {
    if (LED_blink_timer > LED_blink_period) {
      // Toggle LED
      LED_blink_timer = 0;
      digitalWrite(LED_HEATER, !digitalRead(LED_HEATER));
    }
    else {
      LED_blink_timer++;
    }
  }
  if (thermocoupleTimer > thermocouplePeriod) {
    // read temperature every second
    thermocoupleTemperature = thermocouple.readCelsius();
    thermocoupleTimer = 0;
  }
  else {
    thermocoupleTimer ++;
  }
  if(SSRenabled){
    if (SSRon && (SSRonTimer > SSRPeriod_on)) {
      // turn off the heater
      digitalWrite(CONTROL_HEATER, LOW);
      SSRonTimer = 0;
      SSRon = false;
    }
    else {
      SSRonTimer ++;
    }
  
    if (!SSRon && (SSRoffTimer > SSRPeriod_off)) {
      // Now that we are done with the "off" portion of the duty cycle
      // turn on the heater
      digitalWrite(CONTROL_HEATER, HIGH);
      SSRoffTimer = 0;
      SSRon = true;
    }
    else {
      SSRoffTimer ++;
    }
  }
  else{
    //turn off the SSR just in case
    digitalWrite(CONTROL_HEATER, LOW);
  }
  portEXIT_CRITICAL_ISR(&timerMux);

}

void setup_timers() {
  // Setup Timers
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000, true);
  timerAlarmEnable(timer);
}

void set_dutycycle(double input) {

  if(input == 0){
    SSRenabled = false;
  }
  else{
    SSRenabled = true;
    input = input > 1 ? 1 : input;
    input = input < 0 ? 0 : input;
    input *= 500;
    input = ((int)input % 10 >= 5 ) ? (int)input + (10 - (int)input % 10)  : (int)input;
    input /= 500;
  
    SSRPeriod_on = (double) 1000 * input;
    SSRPeriod_off = 1000 - SSRPeriod_on;
    SSRon = true;
  }  
}
