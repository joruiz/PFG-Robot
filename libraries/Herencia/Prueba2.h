#ifndef PRUEBA2_H
#define PRUEBA2_H

#include "Arduino.h"
#include "Prueba.h"

class Prueba2 : public Prueba{
  
  public:
    Prueba2();
    void sendMessage();
    void presentacion_prueba();
    void explicacion_prueba();
    void enunciado_prueba(int nivel);
    void realizacion_prueba();
	int feedback_prueba(int puntuacion, int ganar_puntos, int perder_puntos);
	
    const int beep = 9;
    const int tresdosuno = 12;
	const int bien0 = 13;
    const int mal0 = 14;
    const int sonido_intro = 17;
	const int bocina_empezar = 20;
    const int tit_prueba2 = 23;
    const int exp_prueba2 = 24;
	const int orden_directo_prueba1 = 37;
	const int orden_inverso_prueba1 = 38;
	const int genial_p1 = 27;
	const int muybien_p1 = 28;
	const int bien_p1 = 29;
	const int puntuacionn = 30;
	const int ganar_puntoss = 31;
	const int perder_puntoss = 32;
	const int mal_tiempo = 34;
	const int mal_p1 = 35;

	
	int led_verde = 9;
	int led_rojo = 8;
	
	

    int versiones;
	int vers;
    int segundos;
	int segundos_prueba;
    int long_maxima;
	int nivel_prueba;
	String ans_juego;
	String ans_correct;
	int respuesta = 0;
	char b;
	
	String dataReceived = "";
    String parameters;
    String command;
    String message;
	int OK5 = 0;
	long int tiempo = 0;
};

#endif
