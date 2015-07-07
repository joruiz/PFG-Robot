#ifndef PRUEBA6_H
#define PRUEBA6_H

#include "Arduino.h"
#include "Prueba.h"

class Prueba6 : public Prueba{
  
  public:
    Prueba6();
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
    const int tit_prueba6 = 190;
    const int exp_prueba6 = 192;
	const int enun_prueba61 = 194;
	const int enun_prueba32 = 90;
	const int genial_p1 = 27;
	const int muybien_p1 = 28;
	const int bien_p1 = 29;
	const int puntuacionn = 30;
	const int ganar_puntoss = 31;
	const int perder_puntoss = 32;
	const int mal_tiempo = 34;
	const int mal_p1 = 35;
	const int juego3_terminado = 140;

	
	int led_verde = 9;
	int led_rojo = 8;
	
	

    int versiones;
	int vers;
    int segundos;
	int estimulos_total;
	int estimulos;
	int son_partida_buenos1 = 400; //sonido de partida en el somo14d de los números
	int son_partida_buenos2 = 409; //sonido de partida en el somo14d de los colores
	int son_partida_buenos3 = 476; //sonido de partida en el somo14d de las letras
	int son_x = 490; //sonido de partida en el somo14d del "X"
	int sonidos_buenos1 = 8; //diferentes sonidos de números
	int sonidos_buenos2 = 8; //diferens sonidos de colores
	int sonidos_buenos3 = 6; //diferens sonidos de letras
	int sonido_vers; //sonido que se escucha en cada momento. Variable aleatoria
	int resp_correctas; //número de respuestas correctas
	int resp_inhibir; //respuestas correctas cuando tiene que agitar. Para evitar que lo haga bien si se queda "dormido"
	int resp_inhibir_total; //total de veces que tiene que agitar
    int long_maxima;
	int nivel_prueba;
	unsigned long tiempo;
	unsigned long tiempo1;
	int tiempo_max = 2000;
	int correcto;
	String ans_juego;
	String ans_correct;
	int respuesta = 0;
	char b;
	
	String parameters;
	String dataReceived = "";
};

#endif
