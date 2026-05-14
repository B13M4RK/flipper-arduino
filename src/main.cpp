#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(A10, INPUT);
}

void loop() {
  int valueA10 = analogRead(A10);
  Serial.println(valueA10);
}
