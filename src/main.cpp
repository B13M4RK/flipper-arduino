#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


bool ballWasOnA11 = false;
bool ballWasOnA12 = false;
bool ballWasOnA13 = false;
bool ballWasOnA14 = false;
bool ballWasOnA15 = false;



int counter = 0;
int oldCounter = counter;


void setup() {
  Serial.begin(9600);
  pinMode(A10, INPUT);
  pinMode(A11, INPUT);
  pinMode(A12, INPUT);
  pinMode(A13, INPUT);
  pinMode(A14, INPUT);
  pinMode(A15, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  if (oldCounter != counter) {
    oldCounter = counter;
    lcd.clear();
    lcd.print(counter);
  }


  int valueA10 = analogRead(A10);
  int valueA11 = analogRead(A11);
  int valueA12 = analogRead(A12);
  int valueA13 = analogRead(A13);
  int valueA14 = analogRead(A14);
  int valueA15 = analogRead(A15);


  if (valueA11 <= 200) {
    if (!ballWasOnA11) {
      ballWasOnA11 = true;
      counter += 100;
    }
  } else {
    ballWasOnA11 = false;

  }

  if (valueA12 <= 200) {
    if (!ballWasOnA12) {
      ballWasOnA12 = true;
      counter += 100;
    }
  } else {
    ballWasOnA12 = false;

  }
  if (valueA13 <= 200) {
    if (!ballWasOnA13) {
      ballWasOnA13 = true;
      counter += 100;
    }
  } else {
    ballWasOnA13 = false;

  }
  if (valueA14 <= 200) {
    if (!ballWasOnA14) {
      ballWasOnA14 = true;
      counter += 100;
    }
  } else {
    ballWasOnA14 = false;

  }
  if (valueA15 <= 200) {
    if (!ballWasOnA15) {
      ballWasOnA15 = true;
      counter += 100;
    }
  } else {
    ballWasOnA15 = false;

  }

  Serial.println(valueA11);


}
