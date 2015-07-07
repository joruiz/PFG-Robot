#include "BarGraph.h"
#include <Shiftduino.h>

boolean prueba[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
Shiftduino sd(40, 41, 42, 2); //Datapin, Clockpin, Latchpin
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
  bg.addEnergy(1);
  boolean *output = bg.getOutput();
  for (int i = 0; i < 10; i++)
    prueba[i] = output[i];
  sd.setPins(prueba); 
  if (energy == 10) bg.subEnergy(10);
  delay(1000);
}






