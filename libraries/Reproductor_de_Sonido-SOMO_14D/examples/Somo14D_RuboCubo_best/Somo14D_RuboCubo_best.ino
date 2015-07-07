/*
  BasicPlayer
  Play the first song of the microSD memory
 
  This example code is in the public domain.
  
  Connections:
    SOMO-14D clk pin to arduino pin 51
    SOMO-14D data pin to arduino pin 52
    SOMO-14D busy pin to arduino pin 53
*/
 
#include "SOMO14D.h"
SOMO14D somo14d;

const int sonido1 = 8;
const int sonido2 = 4;
const int sonido3 = 5;
const int sonido4 = 6;

void setup() {
  
  Serial.begin(9600);
  somo14d.begin(51, 52, 53);
  }

void loop() {
  
  Serial.println("Sonido \t");
  Serial.println(sonido1);
  somo14d.play_complete(sonido1);
   
  Serial.println("Sonido \t");
  Serial.println(sonido2);
  somo14d.play_complete(sonido2);
   
  Serial.println("Sonido \t");
  Serial.println(sonido3);
  somo14d.play_complete(sonido3);
  
  Serial.println("Sonido \t");
  Serial.println(sonido4);
  somo14d.play_complete(sonido4);
  
}
