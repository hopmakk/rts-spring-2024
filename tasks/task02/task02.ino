

#include <TaskManagerIO.h>

struct PinInfo {
  PinInfo(int pinNumber, int state, int intervalMkS) { _pinNumber = pinNumber; _state = state; _intervalMkS = intervalMkS; }
  PinInfo() {  }
  int _pinNumber;
  int _state;
  int _intervalMkS;
};


PinInfo pinArray[5];


void setup() {
  
  pinArray[0] = PinInfo(3, LOW, 10000);
  pinArray[1] = PinInfo(5, LOW, 1000);
  pinArray[2] = PinInfo(6, LOW, 500);
  pinArray[3] = PinInfo(9, LOW, 100);
  pinArray[4] = PinInfo(10, LOW, 50);


  for(int i=0; i < sizeof(pinArray); i++) 
  {
    pinMode(pinArray[i]._pinNumber, OUTPUT);
  }

  taskManager.schedule(repeatMicros(pinArray[0]._intervalMkS), ChangeState0);
  taskManager.schedule(repeatMicros(pinArray[1]._intervalMkS), ChangeState1);
  taskManager.schedule(repeatMicros(pinArray[2]._intervalMkS), ChangeState2);
  taskManager.schedule(repeatMicros(pinArray[3]._intervalMkS), ChangeState3);
  taskManager.schedule(repeatMicros(pinArray[4]._intervalMkS), ChangeState4);
}



void loop() {
  taskManager.runLoop();
}



int  MksToPerSecondsValue(int mkS) {
  int mksInSecond = 1000000;
  return mksInSecond/mkS;
}

  static void ChangeState0() {
    int i = 0;
     if (pinArray[i]._state == LOW) {
         pinArray[i]._state = HIGH;
     }
     else {
         pinArray[i]._state = LOW;
     }
     digitalWrite(pinArray[i]._pinNumber, pinArray[i]._state);
  }

  static void ChangeState1() {
    int i = 1;
     if (pinArray[i]._state == LOW) {
         pinArray[i]._state = HIGH;
     }
     else {
         pinArray[i]._state = LOW;
     }
     digitalWrite(pinArray[i]._pinNumber, pinArray[i]._state);
  }

  static void ChangeState2() {
    int i = 2;
     if (pinArray[i]._state == LOW) {
         pinArray[i]._state = HIGH;
     }
     else {
         pinArray[i]._state = LOW;
     }
     digitalWrite(pinArray[i]._pinNumber, pinArray[i]._state);
  }

  static void ChangeState3() {
    int i = 3;
     if (pinArray[i]._state == LOW) {
         pinArray[i]._state = HIGH;
     }
     else {
         pinArray[i]._state = LOW;
     }
     digitalWrite(pinArray[i]._pinNumber, pinArray[i]._state);
  }

  static void ChangeState4() {
    int i = 4;
     if (pinArray[i]._state == LOW) {
         pinArray[i]._state = HIGH;
     }
     else {
         pinArray[i]._state = LOW;
     }
     digitalWrite(pinArray[i]._pinNumber, pinArray[i]._state);
  }

  
