#ifndef UOLED_FUNCTIONS_H
#define UOLED_FUNCTIONS_H

#include "Arduino.h"

class uOLED {

public:
  void presentacion();
  void puntuacion (int puntos);
  void suma (int suma);
  void resta (int resta);
  void prueba (int prueba_int, int nivel_int);
  int cuenta_atras(int segundos_prueba, unsigned long start_time);
  unsigned long tiempo;
  int segundos1;
  int segundos2;
  int r = 1;
  int minutos;
  int segundos_mod;
  char segundos_mostrar[3];
  char minutos_mostrar[2];

private:
  int i = 0;
};

#endif
