#define POMODORO 25
#define BREAK 5

#define GREEN 9
#define BLUE 6
#define BUTTON A2

boolean isActive;
boolean isBreak;
long startTime;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void startTimer() {
  startTime = millis();
  isActive = true;
  digitalWrite(GREEN, HIGH);
}

void startBreak() {
  isActive = false;
  isBreak = true;
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
}

void done() {
  isBreak = false;
  digitalWrite(BLUE, LOW);
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
  } else if (digitalRead(BUTTON)) {
    startTimer();
  } 
}
