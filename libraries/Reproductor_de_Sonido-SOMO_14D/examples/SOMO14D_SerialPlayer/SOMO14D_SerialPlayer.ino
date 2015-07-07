/*
  BasicPlayer
  Play the first song of the microSD memory
 
  This example code is in the public domain.
  
  Connections:
    SOMO-14D clk pin to arduino pin 3
    SOMO-14D data pin to arduino pin 4
    SOMO-14D busy pin to arduino pin 6
*/
 
#include "SOMO14D.h"
SOMO14D somo14d;

void setup() {
  
  Serial.begin(9600);
  somo14d.begin(3, 4, 6);

}

void loop() {
  int song;
  if (Serial.available() != 0) {
    song = Serial.read()-48;
    somo14d.play(song);
    Serial.flush();
  }
}
