#include "Arduino.h"
void exam_1(){
  int myNumbers[] = {0,2,4,16,17};
  void exam_1setup() {
    for (int i = 0; i <= 4; i++) {
      pinMode(myNumbers[i], OUTPUT); // Set the pins as OUTPUT
    }
  }
  void exam_1loop() {
    for(int i=0;i<=4;i++){
      digitalWrite(myNumbers[i],HIGH);
      delay(100);
    }
    for(int i=4;i>=0;i--){
      digitalWrite(myNumbers[i],LOW);
      delay(100);
    }
  }
}
///////////////////////////////////////////////
void exam_2(){
  #define LDR_PIN 12
  int val_ldr = 0;
  int xxx[] = {0, 0, 0, 0};
  int led[] = {2, 0, 4, 16};
  void exam_2setup() {
    Serial.begin(115200);
    for (int i = 0; i < 4; i++) {
      pinMode(led[i], OUTPUT); 
    }
    pinMode(LDR_PIN, INPUT);}
  void exam_2loop() {
    val_ldr = map(analogRead(LDR_PIN),32,4063,1,255);
    Serial.println(val_ldr);
    analogWrite(led[0], val_ldr);
    for (int i = 1; i < 4; i++) {
      xxx[i] = 0; }
    if (val_ldr <= 70) {
      xxx[1] = 1;
    } else if (val_ldr > 70 && val_ldr < 200) {
      xxx[2] = 1;
    } else {
      xxx[3] = 1;}
    for (int i = 1; i < 4; i++) {
      digitalWrite(led[i], xxx[i]);
    }
    delay(100);
  }
}
