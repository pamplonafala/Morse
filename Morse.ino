

#include "Morse.h"
int ledPin = LED_BUILTIN;
int u = 200; //time unit in millisecons
Morse morse(ledPin, u);

void setup() {}

void startSignal() {
  //5 BLINKS
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  delay(u-100);
  
  //DOT LENGTH FOR UNIT RECOGNIZING 
  digitalWrite(ledPin, HIGH);
  delay(u);
  digitalWrite(ledPin, LOW);
  delay(u);

  //3 MORE BLINKS
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  delay(3*u-100);
}

void loop() {
  startSignal();
  morse.emit("helo world");
}
