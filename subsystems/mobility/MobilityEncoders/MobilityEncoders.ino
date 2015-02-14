#include <Wire.h>

struct encoder{
  uint8_t pinA;
  uint8_t pinB;
  uint8_t interrupt;
  int16_t position;
};

encoder e1={2,4,0},e2={3,5,1},e3={19,17,4},e4={18,16,5};
unsigned long encUpdateTime_;

//!---------------------------------------------------------------!//
//!---------------------------------------------------------------!//
//!---------------------------------------------------------------!//
#define _NOT_IMPLEMENTED  (uint8_t)0x26
#define _WHO_AM_I         (uint8_t)0x06

uint8_t i2cReadAddress_;
boolean receivingCommand;
unsigned char encMsg[9];
void i2cOnRequest() {
  switch (i2cReadAddress_) {
   case 0x00:
     Wire.write(_WHO_AM_I);
     break;     
   case 0x51:
     encMsg[0] = (uint8_t)(millis() - encUpdateTime_);

     encMsg[1] = ((unsigned char*)(unsigned long)&(e1.position))[0];
     encMsg[2] = ((unsigned char*)(unsigned long)&(e1.position))[1];
     
     encMsg[3] = ((unsigned char*)(unsigned long)&(e2.position))[0];
     encMsg[4] = ((unsigned char*)(unsigned long)&(e2.position))[1];
     
     encMsg[5] = ((unsigned char*)(unsigned long)&(e3.position))[0];
     encMsg[6] = ((unsigned char*)(unsigned long)&(e3.position))[1];
     
     encMsg[7] = ((unsigned char*)(unsigned long)&(e4.position))[0];
     encMsg[8] = ((unsigned char*)(unsigned long)&(e4.position))[1];
     
     encUpdateTime_ = millis();
     e1.position = 0;
     e2.position = 0;
     e3.position = 0;
     e4.position = 0;
     
     Wire.write(encMsg,9);
     break;
   default:
     Wire.write(_NOT_IMPLEMENTED);
     break;
  }
  i2cReadAddress_ += 1;
}

void i2cOnReceive(int bytes) {
  switch (Wire.read()) {
//    case 0x6A:
//      if(Wire.available() != _DRIVE_MSG_LENGTH)           	//! ERROR IN MESSAGE LENGTH!!! IGNORE MESSAGE...
//        { while(Wire.available()) Wire.read(); return; }
//      en = (Wire.read() == 0)?1:0;
//      driveUpdateTime_ = millis();
//      return;
    case 0x51:
      i2cReadAddress_ = 0x51;
      while(Wire.available()) Wire.read();
      return;
    default:
      while(Wire.available()) Wire.read();
      return;
  }
}

void i2cInit() {
  Wire.begin(_WHO_AM_I);
  Wire.onReceive(i2cOnReceive);
  Wire.onRequest(i2cOnRequest);
  i2cReadAddress_ = 0;
  receivingCommand = 0;
}

//!---------------------------------------------------------------!//
//!---------------------------------------------------------------!//
//!---------------------------------------------------------------!//


void doEncoder1 () {
  if (digitalRead(e1.pinA)) digitalRead(e1.pinB) ? e1.position++ : e1.position--;
  else digitalRead(e1.pinB) ? e1.position-- : e1.position++;
};
void doEncoder2 () {
  if (digitalRead(e2.pinA)) digitalRead(e2.pinB) ? e2.position++ : e2.position--;
  else digitalRead(e2.pinB) ? e2.position-- : e2.position++;
};
void doEncoder3 () {
  if (digitalRead(e3.pinA)) digitalRead(e3.pinB) ? e3.position++ : e3.position--;
  else digitalRead(e3.pinB) ? e3.position-- : e3.position++;
};
void doEncoder4 () {
  if (digitalRead(e4.pinA)) digitalRead(e4.pinB) ? e4.position++ : e4.position--;
  else digitalRead(e4.pinB) ? e4.position-- : e4.position++;
};

void setup() {
  i2cInit();
  Serial.begin(115200);
  // set pin a and b to be input
  pinMode(e1.pinA, INPUT);
  pinMode(e1.pinB, INPUT);
  pinMode(e2.pinA, INPUT);
  pinMode(e2.pinB, INPUT);
  pinMode(e3.pinA, INPUT);
  pinMode(e3.pinB, INPUT);
  pinMode(e4.pinA, INPUT);
  pinMode(e4.pinB, INPUT);
  
  // and turn on pullup resistors
  digitalWrite(e1.pinA, HIGH);
  digitalWrite(e1.pinB, HIGH);
  digitalWrite(e2.pinA, HIGH);
  digitalWrite(e2.pinB, HIGH);
  digitalWrite(e3.pinA, HIGH);
  digitalWrite(e3.pinB, HIGH);
  digitalWrite(e4.pinA, HIGH);
  digitalWrite(e4.pinB, HIGH);
  
  e1.position = 0;
  e2.position = 0;
  e3.position = 0;
  e4.position = 0;
  
  attachInterrupt(e1.interrupt, doEncoder1, RISING);
  attachInterrupt(e2.interrupt, doEncoder2, RISING);
  attachInterrupt(e3.interrupt, doEncoder3, RISING);
  attachInterrupt(e4.interrupt, doEncoder4, RISING);
}

void loop() {
  
}
