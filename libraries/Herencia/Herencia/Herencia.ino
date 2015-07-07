#include "Prueba.h"
#include "Prueba1.h"
#include "Prueba2.h"

Prueba *miPrueba;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  miPrueba = new Prueba1();
  miPrueba->sendMessage();
  delay(1000);
  miPrueba = new Prueba2();
  miPrueba->sendMessage();
  delay(1000);  
}
