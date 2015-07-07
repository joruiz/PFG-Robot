#ifndef EASYVR_FUNCTIONS_H
#define EASYVR_FUNCTIONS_H

#include "Arduino.h"

class EasyVR_fun {

public:
  int recognize(int group, int time);

private:
  int recognize_ans;
  int idx;
  const int recon_time = 18;
  const int recon_understand = 19;
  const int beep = 9;
  enum Groups {GROUP_1  = 1, GROUP_2  = 2};
  enum Group1 {G1_SI = 0, G1_NO = 1};
  enum Group2 {G2_A = 0, G2_I = 1, G2_U = 2};
};

#endif
