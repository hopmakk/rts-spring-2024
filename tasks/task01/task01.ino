struct PinInfo {
  int _pinNumber;
  int _state;
  unsigned long _timerCounter;
  long _interval;

  
  void ChangeState() {
     if (_state == LOW) {
         _state = HIGH;
     }
     else {
         _state = LOW;
     }
  }
};



struct PinInfo pinArray[5] = {
    {3,  LOW, 0, 10000},
    {5,  LOW, 0, 1000},
    {6,  LOW, 0, 500},
    {9,  LOW, 0, 100},
    {10, LOW, 0, 50}
  };



void setup() {
  
  for(int i=0; i < sizeof(pinArray); i++) 
  {
    pinMode(pinArray[i]._pinNumber, OUTPUT);
  }
}



void loop() {

  unsigned long currentMicroSec = micros();

  for(int i=0; i < sizeof(pinArray); i++) 
  {
    if (currentMicroSec - pinArray[i]._timerCounter >= pinArray[i]._interval) 
    {
      pinArray[i]._timerCounter = currentMicroSec;
      pinArray[i].ChangeState();
      digitalWrite(pinArray[i]._pinNumber, pinArray[i]._state);
    }
  }
}

