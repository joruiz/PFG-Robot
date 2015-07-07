#include "BarGraph.h"

void BarGraph::begin(){

  energy = 0;
  updateBarGraph(); 
}

void BarGraph::addEnergy(int value){

  energy += value;
  if (energy > 10)
    energy = 10;
  updateBarGraph();
}

void BarGraph::subEnergy(int value){

  energy -= value;
  if (energy < 0)
    energy = 0;
  updateBarGraph();
}

void BarGraph::presentation_down(){
  
  for (int i = 0; i < 10; i++){
    subEnergy(1);
    updateBarGraph();
    delay(400);
  }
}

void BarGraph::presentation_up(){
	
  for (int i = 0; i < 10; i++) {
    addEnergy(1);
    updateBarGraph();
    delay(400);
  }
}

int BarGraph::getEnergy(){

  return energy;   
}

void BarGraph::updateBarGraph(){

  int i;
  for (i = 0; i < energy; i++)
    output[i] = 1;
  for (; i < 10; i++)
    output[i] = 0;
}

boolean *BarGraph::getOutput(){

  return output;
}

void BarGraph::reset(){
  energy = 0;
  updateBarGraph();
}
