#include "BarGraph.h"
#include <Shiftduino.h>

boolean prueba[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
Shiftduino sd(8, 10, 9, 2);
BarGraph bg;

void setup() {
  bg.begin();
  boolean *output = bg.getOutput();
  for (int i = 0; i < 10; i++)
    prueba[i] = output[i];
  sd.setPins(prueba);
  Serial.begin(9600);
}

void loop() {
  int energy = bg.getEnergy();
  Serial.println(energy);
  bg.addEnergy(10);
  boolean *output = bg.getOutput();
  for (int i = 0; i < 10; i++)
    prueba[i] = output[i];
  sd.setPins(prueba); 
  if (energy == 100) bg.subEnergy(100);
  delay(1000);
}






