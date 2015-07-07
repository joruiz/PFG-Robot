#include "Arduino.h"
#include "Platform.h"
#include "SoftwareSerial.h"
#include "EasyVR.h"
#include "SOMO14D.h"

EasyVR easyvr(Serial1);

enum Groups {GROUP_1  = 1, GROUP_2  = 2};
enum Group1 {G1_SI = 0, G1_NO = 1};
enum Group2 {G2_A = 0, G2_I = 1, G2_U = 2};

//EasyVRBridge bridge;

int8_t group, idx;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  easyvr.setPinOutput(EasyVR::IO1, LOW);
  easyvr.setTimeout(4);
  group = 1;
}

void action(){
    switch (group)
    {
    case GROUP_1:
      switch (idx)
      {
      case G1_SI:
        Serial.println("Si");
        break;
      case G1_NO:
        Serial.println("No");
        break;
      }
      break;
    case GROUP_2:
      switch (idx)
      {
      case G2_A:
        Serial.println("A");
        break;
      case G2_I:
        Serial.println("I");
        break;
      case G2_U:
        Serial.println("U");
        break;
      }
      break;
    }
}

void loop() {
  Serial.print("Say a command in Group ");
  Serial.println(group);
  easyvr.recognizeCommand(group);
  while (!easyvr.hasFinished());

  idx = easyvr.getCommand();
  action();
  
  if (idx < 0)
  {
    if (easyvr.isTimeout())
      Serial.println("Timed out, try again...");

    else
      Serial.println("I haven't undesrtood you. Repeat again, please");
  }
}


