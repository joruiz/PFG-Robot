#include "Platform.h"
#include "EasyVR.h"
#include "EasyVR_Functions.h"
#include "SOMO14D.h"

int EasyVR_fun::recognize(int group, int time){
  
  EasyVR easyvr(Serial1);
  SOMO14D somo14d;
  
  Serial1.begin(9600);
  
  easyvr.setPinOutput(EasyVR::IO1, LOW);
  easyvr.setTimeout(time);
  if (group == 1) Serial.println("Responde Si o No");
  else 	  Serial.println("Responde A, I o U");
  recognize_ans = 0;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
  while (recognize_ans == 0){
  
    somo14d.stop();
    easyvr.recognizeCommand(group);
    while (!easyvr.hasFinished());
  
    idx = easyvr.getCommand();
  
    switch (group)
      {
      case GROUP_1:	  
        switch (idx)
        {
        case G1_SI:
          recognize_ans = 1;
          break;
        case G1_NO:
          recognize_ans = 2;
          break;
        }
        break;
      case GROUP_2:
        switch (idx)
        {
        case G2_A:
          recognize_ans = 3;
        case G2_I:
          recognize_ans = 4;
          break;
        case G2_U:
          recognize_ans = 5;
          break;
        }
        break;
      }
    
    if (idx < 0)
    {
      if (easyvr.isTimeout()){
        Serial.println("No te he oido...");
        somo14d.play_complete(recon_time);
        somo14d.play_complete(beep);
        } 
  
      else{
        Serial.println("No te he entendido");
        somo14d.play_complete(recon_understand);
        somo14d.play_complete(beep);
        }
    }
  }
  return recognize_ans;
}




