#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(A15, INPUT);
}

void loop() {
  int valueA15 = analogRead(A15);
  Serial.println(valueA15);
}
