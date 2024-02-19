#include "Arduino.h"

void exam_1setup() {
  int myNumbers[] = {0, 2, 4, 16, 17};
  for (int i = 0; i <= 4; i++) {
    pinMode(myNumbers[i], OUTPUT); // Set the pins as OUTPUT
  }
}

void exam_1loop() {
  int myNumbers[] = {0, 2, 4, 16, 17};
  for (int i = 0; i <= 4; i++) {
    digitalWrite(myNumbers[i], HIGH);
    delay(100);
  }
  for (int i = 4; i >= 0; i--) {
    digitalWrite(myNumbers[i], LOW);
    delay(100);
  }
}

void exam_2setup() {
  #define LDR_PIN 12
  int led[] = {2, 0, 4, 16};
  pinMode(LDR_PIN, INPUT);
  Serial.begin(115200);
  for (int i = 0; i < 4; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void exam_2loop() {
  #define LDR_PIN 12
  int val_ldr = 0;
  int xxx[] = {0, 0, 0, 0};
  int led[] = {2, 0, 4, 16};

  val_ldr = map(analogRead(LDR_PIN), 32, 4063, 1, 255);
  Serial.println(val_ldr);
  analogWrite(led[0], val_ldr);
  for (int i = 1; i < 4; i++) {
    xxx[i] = 0;
  }
  if (val_ldr <= 70) {
    xxx[1] = 1;
  } else if (val_ldr > 70 && val_ldr < 200) {
    xxx[2] = 1;
  } else {
    xxx[3] = 1;
  }
  for (int i = 1; i < 4; i++) {
    digitalWrite(led[i], xxx[i]);
  }
  delay(100);
}

///////////////////////////////////////
/*
void exam_1setup() {
  
}
void exam_1loop() {
  
}
*/
///////////////////////////////////////

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
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  int distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance <= distanceThreshold) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(bz, HIGH);
    delay(100);
    digitalWrite(bz, LOW);
  } else if (distance <= distanceThreshold+5) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(bz, HIGH);
    delay(300);
    digitalWrite(bz, LOW);
  } else if (distance <= distanceThreshold+10) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(bz, HIGH);
    delay(500);
    digitalWrite(bz, LOW);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(bz, LOW);
  }
  delay(10);
}
