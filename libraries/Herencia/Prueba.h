#ifndef PRUEBA_H
#define PRUEBA_H

#include "Arduino.h"

class Prueba{

public:
  Prueba();
  virtual void sendMessage();
  virtual void presentacion_prueba();
  virtual void explicacion_prueba();
  virtual void enunciado_prueba(int nivel);
  virtual void realizacion_prueba();
  virtual int feedback_prueba(int puntuacion, int ganar_puntos, int perder_puntos);
};

#endif

