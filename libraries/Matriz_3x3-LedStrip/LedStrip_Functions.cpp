#include "PololuLedStrip.h"
#include "LedStrip_Functions.h"
  
void LedStrip_fun::matrix_led(int led, rgb_color color, int time) {
  
  PololuLedStrip<12> ledStrip;
  
  rgb_color colors[led_total];

  rgb_color NONE;
  NONE.red = 0;
  NONE.green = 0;
  NONE.blue = 0;
  
  for(uint16_t i = 0; i < led_total; i++) {
     colors[i] = NONE;
  }
  colors[led] = color;
  ledStrip.write(colors, led_total);
  delay(time);
  for(uint16_t i = 0; i < led_total; i++) {
     colors[i] = NONE;
  }
  ledStrip.write(colors, led_total);
}

void LedStrip_fun::matrix_general(rgb_color color, int time) {
  
  PololuLedStrip<12> ledStrip;

  rgb_color colors[led_total];
  
  rgb_color NONE;
  NONE.red = 0;
  NONE.green = 0;
  NONE.blue = 0;

  for(uint16_t i = 0; i < led_total; i++) {
     colors[i] = color;
  }
  
  ledStrip.write(colors, led_total);
  delay(time);
  
  for(uint16_t i = 0; i < led_total; i++) {
     colors[i] = NONE;
  }
  
  ledStrip.write(colors, led_total);
}
 
void LedStrip_fun::matrix_blink(rgb_color color) {
  
  PololuLedStrip<12> ledStrip;
  
  rgb_color NONE;
  NONE.red = 0;
  NONE.green = 0;
  NONE.blue = 0;
  
  rgb_color colors[led_total];
  
  matrix_general(NONE, 100);
  matrix_general(color, 100);
  matrix_general(NONE, 100);
  matrix_general(color, 100);
  matrix_general(NONE, 100);
  matrix_general(color, 100);
  matrix_general(NONE, 100);
  matrix_general(color, 100);  
  matrix_general(NONE, 100);
  matrix_general(color, 100);
  matrix_general(NONE, 20);  
} 
  
void LedStrip_fun::matrix_welcome() {
  
  PololuLedStrip<12> ledStrip;
  
  rgb_color colors[led_total];
  
  rgb_color NONE;
  NONE.red = 0;
  NONE.green = 0;
  NONE.blue = 0;
  
  rgb_color GREEN;
  GREEN.red = 0;
  GREEN.green = 255;
  GREEN.blue = 0;
  
  rgb_color BLUE;
  BLUE.red = 0;
  BLUE.green = 0;
  BLUE.blue = 255;
  
  rgb_color RED;
  RED.red = 255;
  RED.green = 0;
  RED.blue = 0;
  
  rgb_color PURPLE;
  PURPLE.red = 255;
  PURPLE.green = 0;
  PURPLE.blue = 255;
  
  rgb_color YELLOW;
  YELLOW.red = 255;
  YELLOW.green = 255;
  YELLOW.blue = 0;
  
  rgb_color WHITE;
  WHITE.red = 255;
  WHITE.green = 255;
  WHITE.blue = 255;
  
  matrix_led(6, RED, 200);
  matrix_led(7, BLUE, 200);
  matrix_led(8, WHITE, 200);
  matrix_led(5, YELLOW, 200);
  matrix_led(4, GREEN, 200);
  matrix_led(3, PURPLE, 200);
  matrix_led(0, RED, 200);
  matrix_led(1, BLUE, 200);
  matrix_led(2, GREEN, 200);
  
  matrix_general(PURPLE, 100);
  matrix_general(NONE, 100);
  matrix_general(YELLOW, 100);
  matrix_general(NONE, 100);
  matrix_general(BLUE, 100);
  matrix_general(NONE, 100);
  matrix_general(GREEN, 100);
  matrix_general(NONE, 100);
  matrix_general(RED, 100);  
  matrix_general(NONE, 100);
  matrix_general(WHITE, 100);
  matrix_general(NONE, 20);   
}


