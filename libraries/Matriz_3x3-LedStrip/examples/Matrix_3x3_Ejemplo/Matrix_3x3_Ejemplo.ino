#include "PololuLedStrip.h"
#include "LedStrip_Functions.h"

LedStrip_fun ledstrip_fun;

void setup() {
  
  rgb_color NONE;
  NONE.red = 0;
  NONE.green = 0;
  NONE.blue = 0;
  
  ledstrip_fun.matrix_general(NONE, 200);
}

void loop() {
  
  rgb_color GREEN;
  GREEN.red = 0;
  GREEN.green = 255;
  GREEN.blue = 0;
  
  rgb_color BLUE;
  BLUE.red = 0;
  BLUE.green = 0;
  BLUE.blue = 255;
  
  rgb_color RED;
  RED.red = 0;
  RED.green = 255;
  RED.blue = 0;
  
  rgb_color PURPLE;
  PURPLE.red = 0;
  PURPLE.green = 255;
  PURPLE.blue = 255;
  
  rgb_color YELLOW;
  YELLOW.red = 255;
  YELLOW.green = 255;
  YELLOW.blue = 0;
  
  rgb_color WHITE;
  WHITE.red = 255;
  WHITE.green = 255;
  WHITE.blue = 255;
 
  ledstrip_fun.matrix_welcome();
  delay(2000);
   
  ledstrip_fun.matrix_blink(WHITE);
  delay(2000);
  
  ledstrip_fun.matrix_led(7, BLUE, 1000);  
  ledstrip_fun.matrix_led(3, RED, 1000); 
  ledstrip_fun.matrix_led(6, YELLOW, 1000);
  delay(2000);  
}
