#include "Prueba3.h"
#include "SOMO14D.h"
#include "uOLED_Functions.h"
#include "LedStrip_Functions.h"
#include "Hardware.h"
#include "Protocol.h"
#include "SoftwareSerial.h"

Prueba3::Prueba3(){

}

void Prueba3::sendMessage(){
 
 Serial.println("Mensaje de Prueba3");
 
}

void Prueba3::presentacion_prueba(){
  
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
  somo14d.play_complete(sonido_intro);
  somo14d.play_complete(tit_prueba3);
  
}

void Prueba3::explicacion_prueba(){
  
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
  somo14d.play_complete(exp_prueba3);

}

void Prueba3::enunciado_prueba(int nivel){
   
  nivel_prueba = nivel;
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  estimulos = 0;
  resp_correctas = 0;
  resp_agitar = 0;
  
  PololuLedStrip<12> ledStrip;
  
  LedStrip_fun ledstrip_fun;
  
  rgb_color colors[led_total];
  
  rgb_color GREEN;
  GREEN.red = 0;
  GREEN.green = 255;
  GREEN.blue = 0;
  
  rgb_color BLUE;
  BLUE.red = 0;
  BLUE.green = 0;
  BLUE.blue = 255;
  
  rgb_color RED;
  RED.red = 255;
  RED.green = 0;
  RED.blue = 0;
  
  rgb_color PURPLE;
  PURPLE.red = 255;
  PURPLE.green = 0;
  PURPLE.blue = 255;
  
  rgb_color YELLOW;
  YELLOW.red = 255;
  YELLOW.green = 255;
  YELLOW.blue = 0;
  
  rgb_color WHITE;
  WHITE.red = 255;
  WHITE.green = 255;
  WHITE.blue = 255;
  
  switch(nivel){
	
	//Nivel 1
    
    case(1):
      versiones = 1;
      vers = random(1, versiones+1);
      Serial.print("Version\t");
      Serial.println(vers);
      
      estimulos_total = 15;
	  resp_agitar_total = 4;

      somo14d.play_complete(enun_prueba31);
      somo14d.play_complete(bocina_empezar);	  
      
      switch(vers){
        
        //Prueba 3.1.1
        case(1):
		  
		  while (estimulos < (estimulos_total)){
			  estimulos += 1;
			  Serial.print("Estimulos:\t");
			  Serial.println(estimulos);
			  ans_juego = "";
			  Serial3.flush();
			  if (estimulos == 3 || estimulos == 8 || estimulos == 10 || estimulos == 14){
				  correcto = 0;
				  sonido_vers = random(son_partida_buenos1, son_partida_buenos1+sonidos_buenos1+1);
				  somo14d.play_complete(sonido_vers);
				  Serial.print("Sonido:\t");
				  Serial.println(sonido_vers);
				  tiempo = 0;
				  tiempo1 = millis();
				  Serial3.flush();
				  while (tiempo < tiempo_max && correcto == 0){
					  while(Serial3.available() != 0 && correcto == 0){
						char data = Serial3.read();
							dataReceived += data;
							}
					  int index = dataReceived.indexOf(END_COMMAND);
					  if (index != -1) {
						//get message, execute it and remove from receive bytes
						String message = dataReceived.substring(0, index);
						dataReceived = dataReceived.substring(index + 1);
						Serial.println("Msg. Received: " + message);
						String command = getCommand(message);
						Serial.println("Command: " + command);
						if (command.equals("SHAKE_ON")) {
						  String parameters = getParameters(message);
						  if (numberOfParameters(parameters) == 1)
							byte shake_id = getParameter(parameters, 0).toInt();
						  Serial.println("Parameters: " + parameters);
						  Serial.write(END_COMMAND);
						  if (parameters.equals("3")){
							  correcto = 1;
							  resp_correctas += 1;
							  resp_agitar += 1;
                              ledstrip_fun.matrix_general(GREEN, 500);							  
						  }  
					    }
					  }  
					  tiempo = millis()-tiempo1;
				    }  
						  
					  //Serial.println(ans_juego);
	                  Serial3.flush();  
					  tiempo = millis()-tiempo1;
					  if (correcto == 0) ledstrip_fun.matrix_general(RED, 500);
				  }
                  			  
			  
			  else {
				  Serial3.flush();
				  ans_juego = "";
				  correcto = 1;
				  sonido_vers = random(son_partida_malos, son_partida_malos+sonidos_malos+1);
				  somo14d.play_complete(sonido_vers);
				  Serial.print("Sonido:\t");
				  Serial.println(sonido_vers);
				  //ans_juego = "";
				  Serial3.flush();
				  tiempo = 0;
				  tiempo1 = millis();
				  while (tiempo < tiempo_max && correcto == 1){
					  while(Serial3.available() != 0 && correcto == 1){
						char data = Serial3.read();
							dataReceived += data;
							}
					  int index = dataReceived.indexOf(END_COMMAND);
					  if (index != -1) {
						//get message, execute it and remove from receive bytes
						String message = dataReceived.substring(0, index);
						dataReceived = dataReceived.substring(index + 1);
						Serial.println("Msg. Received: " + message);
						String command = getCommand(message);
						Serial.println("Command: " + command);
						if (command.equals("SHAKE_ON")) {
						  String parameters = getParameters(message);
						  if (numberOfParameters(parameters) == 1)
							byte shake_id = getParameter(parameters, 0).toInt();
						  Serial.println("Parameters: " + parameters);
						  Serial.write(END_COMMAND);
                          if (parameters.equals("3")){
							  correcto = 0;
							  ledstrip_fun.matrix_general(RED, 500);
						  }  						  
					    } 
					  }
				   tiempo = millis()-tiempo1;
				   Serial.println(ans_juego);
				   Serial3.flush();  
				  }
                  if (correcto == 1) {
					 resp_correctas += 1;
				     ledstrip_fun.matrix_general(GREEN, 500);
			        }	
                  Serial.println(tiempo);					
			  }
		  }
			  somo14d.play_complete(juego3_terminado);
			  Serial.print("\nRespuestas correctas: ");
			  Serial.println(resp_correctas);
          break;		  
			
          //Se pueden añadir futuras versiones -> Cambiar el número de versiones arriba
		  
		  }
		  
      break;
    
	//Nivel 3
    
    case(3):
      versiones = 1;
      vers = random(1, versiones+1);
      Serial.print("Version\t");
      Serial.println(vers);
      
      estimulos_total = 30;
	  resp_agitar_total = 5;

      somo14d.play_complete(enun_prueba32);
      somo14d.play_complete(bocina_empezar);	  
      
      switch(vers){
        
        //Prueba 3.3.1
        case(1):
		  
		  while (estimulos < (estimulos_total)){
			  estimulos += 1;
			  Serial.print("Estimulos:\t");
			  Serial.println(estimulos);
			  ans_juego = "";
			  Serial.flush();
			  if (estimulos == 2 || estimulos == 13 || estimulos == 28){
				  correcto = 0;
				  sonido_vers = random(son_partida_buenos1, son_partida_buenos1+sonidos_buenos1+1);
				  somo14d.play_complete(sonido_vers);
				  Serial.print("Sonido:\t");
				  Serial.println(sonido_vers);
				  tiempo = 0;
				  tiempo1 = millis();
				  while (tiempo < tiempo_max && correcto == 0){
					  while(Serial.available() != 0 && correcto == 0){
						  b = Serial.read();
		                  ans_juego += b;
						  if (ans_juego == "shake1"){
							  correcto = 1;
							  resp_correctas += 1;
							  resp_agitar += 1;
                              ledstrip_fun.matrix_general(GREEN, 500);							  
						  }
						  else if (ans_juego == "shake2"){
							  correcto = 0;
                              ledstrip_fun.matrix_general(RED, 500);							  
						  }
					  }
					  Serial.println(ans_juego); 
					  tiempo = millis()-tiempo1;
				  }
                  if (correcto == 0) ledstrip_fun.matrix_general(RED, 500);			  
			  }
			  else if (estimulos == 8 || estimulos == 21){
				  correcto = 0;
				  sonido_vers = random(son_partida_buenos2, son_partida_buenos2+sonidos_buenos2+1);
				  somo14d.play_complete(sonido_vers);
				  Serial.print("Sonido:\t");
				  Serial.println(sonido_vers);
				  tiempo = 0;
				  tiempo1 = millis();
				  while (tiempo < tiempo_max && correcto == 0){
					  while(Serial.available() != 0 && correcto == 0){
						  b = Serial.read();
		                  ans_juego += b;
						  if (ans_juego == "shake2"){
							  correcto = 1;
							  resp_correctas += 1;
							  resp_agitar += 1;
                              ledstrip_fun.matrix_general(GREEN, 500);							  
						  }
                          else if (ans_juego == "shake1"){
							  correcto = 0;
                              ledstrip_fun.matrix_general(RED, 500);							  
						  }						  
					  }
					  Serial.println(ans_juego);
					  tiempo = millis()-tiempo1;
				  }
                  if (correcto == 0) ledstrip_fun.matrix_general(RED, 500);			  
			  }
			  else {
				  correcto = 1;
				  sonido_vers = random(son_partida_malos, son_partida_malos+sonidos_malos+1);
				  somo14d.play_complete(sonido_vers);
				  Serial.print("Sonido:\t");
				  Serial.println(sonido_vers);
				  tiempo = 0;
				  tiempo1 = millis();
				  while (tiempo < tiempo_max && correcto == 1){
					  while(Serial.available() != 0 && correcto == 1){
						  b = Serial.read();
		                  ans_juego += b;
                          if (ans_juego == "shake1" || ans_juego == "shake2"){
							  correcto = 0;
							  ledstrip_fun.matrix_general(RED, 500);
						  }  						  
					  } 
					  tiempo = millis()-tiempo1;
					  }
				   if (correcto == 1) {
					   resp_correctas += 1;
				       ledstrip_fun.matrix_general(GREEN, 500);
			        }
				   Serial.println(ans_juego);
				   Serial.println(tiempo);
				  }						  
			  }
			  somo14d.play_complete(juego3_terminado);
			  Serial.print("\nRespuestas correctas: ");
			  Serial.println(resp_correctas);
          break;		  
			
          //Se pueden añadir futuras versiones -> Cambiar el número de versiones arriba
		  
		  }
		  
      break;
   }
}

void Prueba3::realizacion_prueba(){
  
  uOLED uoled;
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
}

int Prueba3::feedback_prueba(int puntuacion, int ganar_puntos, int perder_puntos){
	
  uOLED uoled;
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  //SoftwareSerial BT(10,11);
  //BT.begin(9600);
  
  pinMode(led_verde, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  // int demostrar = resp_correctas*100/estimulos;
  // Serial.print("Porcentaje de aciertos: ");
  // Serial.println(demostrar);
  
			if (resp_correctas*100/estimulos > 74 && resp_agitar*100/resp_agitar_total > 74){
				puntuacion = puntuacion + ganar_puntos;
				digitalWrite(led_verde, HIGH);
				if (resp_correctas*100/estimulos > 90) somo14d.play_complete(genial_p1);
				else somo14d.play_complete(muybien_p1);
				somo14d.play_complete(ganar_puntoss);
				uoled.suma(ganar_puntos);
                delay(1500);	
			}
			
			else {
				puntuacion = puntuacion - perder_puntos;
				if(puntuacion < 0) puntuacion = 0;
				digitalWrite(led_rojo, HIGH);
			    somo14d.play_complete(mal_p1); //Hacer un sonido específico para esta prueba
				somo14d.play_complete(perder_puntoss);
				uoled.resta(perder_puntos);
				delay(1500);
			}
			
	// BT.println("\n");
    // BT.println("Prueba 3");
	// BT.print("Nivel: ");
    // BT.println(nivel_prueba);	
	// BT.print("Respuestas correctas: ");
	// int enviar = resp_correctas*100/estimulos;
	// BT.println(enviar);
	// BT.print("Puntuacion: ");
	// BT.println(puntuacion);
	
	somo14d.play(puntuacionn);
	uoled.puntuacion(puntuacion);
    delay(4500);
	
	return puntuacion;
}