#define H1 1.0
#define H3 1.0
#define r1 1.0
#define r3 1.0
#define W1 1.0
#define W2 1.0
#define W3 1.0

#define FRWD 1
#define BKWD 0
#define ENC_RES 0.01  // in 10 um/count

struct state_t {
  float wheelSpeed[6];
  float steerAngle[4];
  boolean wheelDir[6];
};

struct motor_t {
  uint8_t ena;
  uint8_t dir;
  uint8_t pwm;
  boolean err;
};

struct encoder_t {
  uint8_t pin;
  int16_t position;
};

struct pot_t {
  uint8_t pin;
  uint8_t zero;
  uint8_t max;
  uint8_t min;
};

state_t currState = {{0,0,0,0,0,0}, {0,0,0,0}, {FRWD,FRWD,FRWD,FRWD,FRWD,FRWD}};
state_t destState = {{0,0,0,0,0,0}, {0,0,0,0}, {FRWD,FRWD,FRWD,FRWD,FRWD,FRWD}};
state_t nextState = {{0,0,0,0,0,0}, {0,0,0,0}, {FRWD,FRWD,FRWD,FRWD,FRWD,FRWD}};

//23 1DB2; 27 1DB1; A5 AB1; 3 PB1; 25 1DT2; 29 1DT1; NC AT1; 2 PT1
//47 3DB2; 45 3DB1; A9 AB3; 11 PB3; 46 3DT2; 44 3DT1; A8 AT3; 10 PT3

//43 4DB2; 41 4DB1; A7 AB4; 13 PB4; 42 4DT2; 40 4DT1; A6 AT4; 12 PT4
//39 5DB2; 37 5DB1; A0 AB5; 7  PB5; 38 5DT2; 36 4DT1; A1 AT5; 6  PT5
//35 6DB2; 34 6DB1; NC AB6; 5  PB6; 33 6DT2; 31 6DT1; NC AT6; 4  PT6

motor_t   driveMotor[6] = {{34, 35,  5, 0}, {31, 33,  4, 0}, {36, 38,  6, 0}, {41, 43, 13, 0}, {42, 40, 12, 0}, {37, 39,  7, 0}};
encoder_t encoder[6]    = {{22, 0},         {24, 0},         {26, 0},         {28, 0},         {30, 0},         {32, 0}     };

motor_t   steerMotor[6] = {{27, 23,  3, 0},      {29, 25,  2, 0},     {45, 47, 11, 0},     {44, 46, 10, 0}    };
pot_t     pot[4]        = {{ 9, 173,  308,  38}, { 4, 660, 525, 795}, {10, 458, 593, 323}, { 3, 555, 690, 420}};

unsigned long encUpdateTime = 0;

void onEncoder1Change() {
  (currState.wheelDir[1] == FRWD) ? encoder[1].position++ : encoder[1].position--;
};
void onEncoder4Change() {
  (currState.wheelDir[4] == FRWD) ? encoder[4].position++ : encoder[4].position--;
};

void wheelSpeedUpdate() {
  uint8_t time = millis() - encUpdateTime;
  float scale = ENC_RES / time;
  for( int i = 0; i < 6; i++) {
    currState.wheelSpeed[i] = encoder[i].position * scale;
    encoder[i].position = 0;
  }
  encUpdateTime = millis();
}

void speedFeedbackInit() {
  for( int i = 0; i < 6; i++) {
    pinMode(encoder[i].pin, INPUT);
  }
  
  attachInterrupt(encoder[0].pin, onEncoder1Change, RISING);
  attachInterrupt(encoder[1].pin, onEncoder1Change, RISING);
  attachInterrupt(encoder[2].pin, onEncoder1Change, RISING);
  attachInterrupt(encoder[3].pin, onEncoder1Change, RISING);
  attachInterrupt(encoder[4].pin, onEncoder1Change, RISING);
  attachInterrupt(encoder[5].pin, onEncoder1Change, RISING);

  encUpdateTime = millis();
}

void steerAnglesUpdate() {
  float ch;
  for( int i = 0; i < 4; i++ ) {
    ch = (unsigned int)(unsigned char)analogRead(pot[i].pin);
    ch = ch - pot[i].zero;
    //map
    currState.steerAngle[i] = ch;
    if (abs(ch) > 45) steerMotor[i].err = 1;
    Serial.print(ch);
    Serial.print("\t");
  }
  Serial.print("\n");
}

void potFeedbackInit() {
  for( int i = 0; i < 4; i++ ) {
    pinMode(pot[i].pin, INPUT);
  }
}

void destCompute(int16_t speed, int8_t encR, int8_t sigR) {
  float R, w;
  if(encR != 0) {
    R = sigR * 1023.0 / ( pow(2.0, encR / 25.0) - 1.0 );
    destState.steerAngle[0] = atan( H1 / ( R - W1/2 ) ) * 180 / PI;
    destState.steerAngle[1] = atan( H3 / ( R - W3/2 ) ) * 180 / PI;
    destState.steerAngle[2] = atan( H3 / ( R + W3/2 ) ) * 180 / PI;
    destState.steerAngle[3] = atan( H1 / ( R + W1/2 ) ) * 180 / PI;
 
    w = speed / R;
    destState.wheelSpeed[0] = w * (sqrt( pow(H1, 2) + pow(R - W1/2, 2) ) - r1);
    destState.wheelSpeed[1] = w * (R - W2/2);
    destState.wheelSpeed[2] = w * (sqrt( pow(H3, 2) + pow(R - W3/2, 2) ) - r3);
    destState.wheelSpeed[3] = w * (sqrt( pow(H3, 2) + pow(R + W3/2, 2) ) - r3);
    destState.wheelSpeed[4] = w * (R + W2/2);
    destState.wheelSpeed[5] = w * (sqrt( pow(H1, 2) + pow(R + W1/2, 2) ) - r1);
  }
  else {
    destState.steerAngle[0] = destState.steerAngle[1] = destState.steerAngle[2] = destState.steerAngle[3] = 0;
    destState.wheelSpeed[0] = destState.wheelSpeed[1] = destState.wheelSpeed[2] = destState.wheelSpeed[3] = destState.wheelSpeed[4] = destState.wheelSpeed[5] = speed;
  }
}

void motorsInit() {
  
}

void nextCompute() {
//decide  
}

void setup() {
  Serial.begin(9600);
  potFeedbackInit();
  speedFeedbackInit();
  //stateFeedbackInit();
  motorsInit();
}

void loop() {
  steerAnglesUpdate();
  wheelSpeedUpdate();
  //stateAngleUpdate();
  destCompute(200, 100, 1);
  nextCompute();
}
