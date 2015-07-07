#include "Arduino.h"
#include "Platform.h"
#include "EasyVR.h"
#include "EasyVR_Functions.h"
#include "SOMO14D.h"

EasyVR_fun easyvr_fun;
int group = 1;
int time = 4;
int recognize_ans;

void setup() {
  Serial.begin(9600);

}

void loop() {
  recognize_ans = easyvr_fun.recognize(group, time);
  if (recognize_ans == 1) Serial.println("Si");
  if (recognize_ans == 2) Serial.println("No");
  if (recognize_ans == 3) Serial.println("A");
  if (recognize_ans == 4) Serial.println("I");
  if (recognize_ans == 5) Serial.println("U");
  recognize_ans = 0;
}


