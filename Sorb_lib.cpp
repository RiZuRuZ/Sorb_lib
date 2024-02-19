#include "Arduino.h"
/*#define BLYNK_TEMPLATE_ID "TMPL6VSAGm9n1"
#define BLYNK_TEMPLATE_NAME "TEST"
#define BLYNK_AUTH_TOKEN "4lQZqwEu5QnRPcnviK2kY9DRsGFyHhkQ"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp32.h>*/

/*
//main
//7ePoF1BYfYdNkzKMphtcB2Ncddi1IMEhZ0dX604zubi
//D1h9vPDmynYSw9R7cvA9s2HMprLv9obFVHbZEhlw5ve

#include <WiFi.h>
#include <HTTPClient.h>
#define SSID  "jaijujew"
#define PASS  "yoki6969"
#define SERVER_NAME "https://notify-api.line.me/api/notify"
#define TOKEN "7ePoF1BYfYdNkzKMphtcB2Ncddi1IMEhZ0dX604zubi"



BLYNK_WRITE(V0)
{   
  get1 = param.asInt();
}




Blynk.begin(BLYNK_AUTH_TOKEN,SSID,PASS);
Blynk.run();
Blynk.virtualWrite(V1, distance);
*/

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
/////////////////////////////////

void exam_4setup() {
  #define trig 21
  #define echo 22
  Servo servo;
  Serial.begin(9600);
  servo.attach(19);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void exam_4loop() {
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); 
  distance = (duration * 0.0343) / 2;

  int servoAngle = map(distance, 0, 30, 0, 180);
  if (distance<=30) {
  servo.write(servoAngle);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Servo Angle: ");
  Serial.println(servoAngle);
  } else{
    Serial.println("Out of range");
  }
  delay(100);
}
/////////////////////////////////////
void exam_5setup() {
  const int trig = 23;
  const int echo = 22;
  
  LiquidCrystal lcd_1(0, 4, 5, 18, 16, 17);
  
  int bt = 35;
  int poten = 34;
  
  bool a = true;
  lcd_1.begin(16, 2);
  Serial.begin(115200);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(bt, INPUT);
  pinMode(poten, INPUT);
}

void exam_5loop() {
  int check = digitalRead(bt);

  if (check == 1) {
    a = !a;
    delay(1000);
  }

  int value = analogRead(poten);

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println(a);

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
//////////////////////////////////////
/*void exam_6setup() {
  
}
void exam_6loop() {
  
}*/
