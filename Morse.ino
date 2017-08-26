

#include "Morse.h"
String readString;
int ledPin = 13;
int u = 500; //time unit in millisecons
int f; //frequency for tone
Morse morse(ledPin, u, 4000);

void setup() {
  startSignal();
  Serial.begin(9600);
  Serial.println(HIGH);
}

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
  morse.unit();

  //4 MORE BLINKS
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  delay(3*u-100);
}

void loop() {
  String text;
  if (Serial.available() > 0) {
    text = Serial.readString();
    Serial.println("Emitting: " + text);
    morse.emit(text);
    Serial.println("Finished emmiting");
  }
}
