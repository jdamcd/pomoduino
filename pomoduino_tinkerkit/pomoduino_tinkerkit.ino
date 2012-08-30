#include <TinkerKit.h>

#define POMODORO 25
#define BREAK 5

TKLed green(O2);
TKLed blue(O3);
TKButton button(I2);

boolean isActive;
boolean isBreak;
long startTime;

void setup() {}

void startTimer() {
  startTime = millis();
  isActive = true;
  green.on();
}

void startBreak() {
  isActive = false;
  isBreak = true;
  green.off();
  blue.on();
}

void done() {
  isBreak = false;
  blue.off();
}

void checkTimer() {
  long timerMins = (millis() - startTime)/1000/60;
  
  if (isActive && timerMins > POMODORO - 1) {
    startBreak();
  } else if (isBreak && timerMins > (POMODORO + BREAK) - 1) {
    done();
  }
}

void loop() {
  if (isActive || isBreak) {
    checkTimer();
  } else if (button.get() == HIGH) {
    startTimer();
  } 
}
