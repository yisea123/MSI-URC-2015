//#define lFRNT 0
#define lMIDL 0
//#define lREAR 2

//#define rFRNT 5
#define rMIDL 1
//#define rREAR 3

#define FRWD 1
#define BKWD 0

struct _motor{
  int enable;
  int pwm;
  int digital;
};
_motor motor[2] = {{3,5,7}, {4,6,8}};
//_motor motor[6] = {{36,6,38}, {34,5,35},{31,4,33},{37,7,39},{44,10,46},{45,11,47}};

#include <Wire.h>

uint8_t lPWM, rPWM;
boolean lEN, rEN, lDIR, rDIR;
unsigned long driveUpdateTime_;

void stop();
void drive();
void driveInit();

//!---------------------------------------------------------------!//
//!---------------------------------------------------------------!//
//!---------------------------------------------------------------!//
#define _NOT_IMPLEMENTED   (uint8_t)0x26
#define _WHO_AM_I          (uint8_t)0x05
#define _DRIVE_MSG_LENGTH  3
#define _DRIVE_MSG_TIMEOUT 200

uint8_t i2cReadAddress_;
boolean receivingCommand;

void i2cOnRequest() {
  switch (i2cReadAddress_) {
   case 0x00:
     Wire.write(_WHO_AM_I);
     break;
//   case 0x51:
//     while(StateFeedbackUpdating);
//     Wire.write(StateFeedbackMsg, 1);
//     break;
   default:
     Wire.write(_NOT_IMPLEMENTED);
     break;
  }
  i2cReadAddress_ += 1;
}

void i2cOnReceive(int bytes) {
  int8_t power_x, power_y;

  switch (Wire.read()) {
    case 0x5A:
      if(Wire.available() != _DRIVE_MSG_LENGTH)           	//! ERROR IN MESSAGE LENGTH!!! IGNORE MESSAGE...
        { while(Wire.available()) Wire.read(); return; }
      if(Wire.read() != 1) {
        while(Wire.available()) Wire.read();
        stop();
      }
      else {
        receivingCommand = 1;
        
        power_x = Wire.read();
        power_y = Wire.read();
        
        lDIR = ((power_x - power_y) > 0)?1:0;
        rDIR = ((power_x + power_y) > 0)?1:0;
        
        lPWM = min(abs(power_x - power_y)*2,255);
        rPWM = min(abs(power_x + power_y)*2,255);

        lEN = (lPWM == 0)?0:1;
        rEN = (rPWM == 0)?0:1;
        
        receivingCommand = 0;
      }
      driveUpdateTime_ = millis();
      return;
//    case 0x51:
//      i2cReadAddress_ = 0x51;
//      while(Wire.available()) Wire.read();
//      return;
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

void driveInit() {
  for (uint8_t i=0; i < 2; i++) {
    pinMode(motor[i].enable, OUTPUT);
    pinMode(motor[i].pwm, OUTPUT);
    pinMode(motor[i].digital, OUTPUT);
  }    
}

void stop() {
  lEN = 1;
  rEN = 1;
  lPWM = 0;
  rPWM = 0;
  lDIR = FRWD;
  rDIR = FRWD;
  drive();  
}

void drive() {
//  digitalWrite(motor[lFRNT].enable, lEN);
  digitalWrite(motor[lMIDL].enable, lEN);
//  digitalWrite(motor[lREAR].enable, lEN);

//  digitalWrite(motor[rFRNT].enable, rEN);
  digitalWrite(motor[rMIDL].enable, rEN);
//  digitalWrite(motor[rREAR].enable, rEN);

//  digitalWrite(motor[lFRNT].digital, lDIR);
  digitalWrite(motor[lMIDL].digital, lDIR);
//  digitalWrite(motor[lREAR].digital, lDIR);

//  digitalWrite(motor[rFRNT].digital, 1 - rDIR);
  digitalWrite(motor[rMIDL].digital, 1 - rDIR);
//  digitalWrite(motor[rREAR].digital, 1 - rDIR);

//  analogWrite(motor[lFRNT].pwm, (lDIR == FRWD)?(255 - lPWM):lPWM);
  analogWrite(motor[lMIDL].pwm, (lDIR == FRWD)?(255 - lPWM):lPWM);
//  analogWrite(motor[lREAR].pwm, (lDIR == FRWD)?(255 - lPWM):lPWM);

//  analogWrite(motor[rFRNT].pwm, (rDIR == FRWD)?rPWM:(1-rPWM));
  analogWrite(motor[rMIDL].pwm, (rDIR == FRWD)?rPWM:(1-rPWM));
//  analogWrite(motor[rREAR].pwm, (rDIR == FRWD)?rPWM:(1-rPWM));
}

void setup() {
  lEN = 1;
  rEN = 1;
  lPWM = 255;
  rPWM = 255;
  lDIR = FRWD;
  rDIR = BKWD;
  driveUpdateTime_ = 0;
  
  i2cInit();
  Serial.begin(115200);
  driveInit();
  stop();
}

void loop() {
  if (millis() - driveUpdateTime_ >= _DRIVE_MSG_TIMEOUT) stop();
  if (!receivingCommand) {
    drive();
  }
}
