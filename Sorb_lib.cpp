#include "Arduino.h"
#include <Servo.h>
#include <LiquidCrystal.h>

Servo servo;  // Declare Servo globally
bool a = true;  // Declare boolean globally

// Example 1
void exam_1setup() {
  int ledPins[] = {0, 2, 4, 16, 17};
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void exam_1loop() {
  int ledPins[] = {0, 2, 4, 16, 17};
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
  for (int i = 4; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(100);
  }
}

// Example 2
void exam_2setup() {
  const int LDR_PIN = 12;
  int ledPins[] = {2, 0, 4, 16};
  pinMode(LDR_PIN, INPUT);
  Serial.begin(115200);
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void exam_2loop() {
  const int LDR_PIN = 12;
  int valLDR = map(analogRead(LDR_PIN), 32, 4063, 1, 255);
  Serial.println(valLDR);
  analogWrite(2, valLDR);

  int xxx[] = {0, 0, 0, 0};
  int ledPins[] = {2, 0, 4, 16};

  for (int i = 1; i < 4; i++) {
    xxx[i] = 0;
  }

  if (valLDR <= 70) {
    xxx[1] = 1;
  } else if (valLDR > 70 && valLDR < 200) {
    xxx[2] = 1;
  } else {
    xxx[3] = 1;
  }

  for (int i = 1; i < 4; i++) {
    digitalWrite(ledPins[i], xxx[i]);
  }
  delay(100);
}

// Example 3
void exam_3setup() {
  const int trig = 21;
  const int echo = 22;
  const int led1 = 0;
  const int led2 = 5;
  const int led3 = 18;
  const int bz = 2;
  const int distanceThreshold = 5;
  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(bz, OUTPUT);
}

void exam_3loop() {
  long duration = pulseIn(22, HIGH);
  int distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);

  const int distanceThreshold = 5;

  int ledPins[] = {0, 5, 18};
  int bz = 2;

  if (distance <= distanceThreshold) {
    digitalWrite(0, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(18, LOW);
    digitalWrite(bz, HIGH);
    delay(100);
    digitalWrite(bz, LOW);
  } else if (distance <= distanceThreshold + 5) {
    digitalWrite(0, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(18, LOW);
    digitalWrite(bz, HIGH);
    delay(300);
    digitalWrite(bz, LOW);
  } else if (distance <= distanceThreshold + 10) {
    digitalWrite(0, LOW);
    digitalWrite(5, LOW);
    digitalWrite(18, HIGH);
    digitalWrite(bz, HIGH);
    delay(500);
    digitalWrite(bz, LOW);
  } else {
    digitalWrite(0, LOW);
    digitalWrite(5, LOW);
    digitalWrite(18, LOW);
    digitalWrite(bz, LOW);
  }
  delay(10);
}

// Example 4
void exam_4setup() {
  const int trig = 21;
  const int echo = 22;
  Serial.begin(9600);
  servo.attach(19);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void exam_4loop() {
  long duration, distance;
  digitalWrite(21, LOW);
  delayMicroseconds(2);
  digitalWrite(21, HIGH);
  delayMicroseconds(10);
  digitalWrite(21, LOW);
  duration = pulseIn(22, HIGH);
  distance = (duration * 0.0343) / 2;

  int servoAngle = map(distance, 0, 30, 0, 180);
  if (distance <= 30) {
    servo.write(servoAngle);
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm | Servo Angle: ");
    Serial.println(servoAngle);
  } else {
    Serial.println("Out of range");
  }
  delay(100);
}

// Example 5
void exam_5setup() {
  const int trig = 23;
  const int echo = 22;
  LiquidCrystal lcd_1(0, 4, 5, 18, 16, 17);
  int bt = 35;
  int poten = 34;
  lcd_1.begin(16, 2);
  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(bt, INPUT);
  pinMode(poten, INPUT);
}

void exam_5loop() {
  int check = digitalRead(35);

  if (check == 1) {
    a = !a;
    delay(1000);
  }

  int value = analogRead(34);

  digitalWrite(23, LOW);
  delayMicroseconds(2);
  digitalWrite(23, HIGH);
  delayMicroseconds(10);
  digitalWrite(23, LOW);

  long duration = pulseIn(22, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println(a);

  LiquidCrystal lcd_1(0, 4, 5, 18, 16, 17);

  lcd_1.setCursor(0, 0);

  if (a) {
    lcd_1.print("Ultra_sonic!");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Distance: ");
    lcd_1.print(distance);
    lcd_1.print(" CM ");
  } else {
    lcd_1.print("Potentio!     ");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Value: ");
    lcd_1.print(value);
    lcd_1.print("                ");
  }

  delay(100);
}
