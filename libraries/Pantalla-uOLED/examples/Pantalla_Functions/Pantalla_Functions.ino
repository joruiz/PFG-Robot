#include "uOLED_Functions.h"
#include "Goldelox_Serial_4DLib.h"
#include "Goldelox_const4D.h"
#include "SoftwareSerial.h"

uOLED uoled;

int puntuacion = 300;
int mas;
int menos;

void setup() {
  
}

void loop() {
  
  delay(3000);
  puntuacion = puntuacion + mas - menos;
  uoled.puntuacion(puntuacion);
  delay(3000);
  mas = 30;
  uoled.suma(mas);
  delay(3000);
  menos = 10;
  uoled.resta(menos);
  delay(3000);
  int prueba = 1;
  int nivel = 3;
  uoled.prueba(prueba, nivel);  
}
