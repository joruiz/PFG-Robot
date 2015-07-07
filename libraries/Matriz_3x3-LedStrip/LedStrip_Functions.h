#ifndef LEDSTRIP_FUNCTIONS_H
#define LEDSTRIP_FUNCTIONS_H

#include "Arduino.h"
#include "PololuLedStrip.h"

  
class LedStrip_fun {

public:
  void matrix_welcome();
  void matrix_led(int led, rgb_color color, int time);
  void matrix_general(rgb_color color, int time);
  void matrix_blink(rgb_color color);

private:
  #define led_total 9
};

#endif
