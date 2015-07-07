#ifndef BARGRAPH_H
#define BARGRAPH_H

#include "Arduino.h"

class BarGraph {

public:
  void begin();
  void addEnergy(int value);
  void subEnergy(int value);
  void presentation_down();
  void presentation_up();
  int getEnergy();
  boolean *getOutput();
  void reset();

private:
  void updateBarGraph();
  int energy;
  boolean output[10];
};

#endif

