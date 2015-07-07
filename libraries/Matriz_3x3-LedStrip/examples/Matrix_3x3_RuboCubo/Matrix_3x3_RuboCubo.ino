#include "PololuLedStrip.h"
#include "LedStrip_Functions.h"

LedStrip_fun ledstrip_fun;

void setup() {
  
  rgb_color NONEE;
  NONEE.red = 0;
  NONEE.green = 0;
  NONEE.blue = 0;
  
  ledstrip_fun.matrix_general(NONEE, 200);
}

void loop() {
  
  rgb_color GREENN;
  GREENN.red = 0;
  GREENN.green = 255;
  GREENN.blue = 0;
  
  rgb_color BLUEE;
  BLUEE.red = 0;
  BLUEE.green = 0;
  BLUEE.blue = 255;
  
  rgb_color REDD;
  REDD.red = 255;
  REDD.green = 0;
  REDD.blue = 0;
  
  rgb_color PURPLEE;
  PURPLEE.red = 255;
  PURPLEE.green = 0;
  PURPLEE.blue = 255;
  
  rgb_color YELLOWW;
  YELLOWW.red = 255;
  YELLOWW.green = 255;
  YELLOWW.blue = 0;
  
  rgb_color WHITEE;
  WHITEE.red = 255;
  WHITEE.green = 255;
  WHITEE.blue = 255;
 
  ledstrip_fun.matrix_welcome();
  delay(2000);
   
  ledstrip_fun.matrix_blink(WHITEE);
  delay(2000);
  
  ledstrip_fun.matrix_led(7, BLUEE, 1000);  
  ledstrip_fun.matrix_led(3, REDD, 1000); 
  ledstrip_fun.matrix_led(6, YELLOWW, 1000);
  delay(2000);  
}
