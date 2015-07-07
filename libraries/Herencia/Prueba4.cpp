#include "Prueba4.h"
#include "SOMO14D.h"
#include "uOLED_Functions.h"
#include "LedStrip_Functions.h"

Prueba4::Prueba4(){

}

void Prueba4::sendMessage(){
 
 Serial.println("Mensaje de Prueba4");
 
}

void Prueba4::presentacion_prueba(){
  
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
  somo14d.play_complete(sonido_intro);
  somo14d.play_complete(tit_prueba2);
  
}

void Prueba4::explicacion_prueba(){
  
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
  somo14d.play_complete(exp_prueba2);

}

void Prueba4::enunciado_prueba(int nivel){
   
  nivel_prueba = nivel;
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
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
      
      segundos_prueba = 60;
      
      switch(vers){
        
        //Prueba 4.1.1
        case(1):
		  ans_correct = "42perro";
          somo14d.play_complete(enun_prueba111);
          somo14d.play_complete(bocina_empezar);
          break;
		
        //Prueba 4.1.2 (sin hacer)		
		case(2):
		  ans_correct = "4perrogato5";
          somo14d.play_complete(enun_prueba112);
          somo14d.play_complete(bocina_empezar);
          break;
		
        //Prueba 4.1.3 (sin hacer)
		case(3):
		  ans_correct = "134";
          somo14d.play_complete(enun_prueba113);
          somo14d.play_complete(bocina_empezar);
          break;
          
        //Se pueden añadir futuras versiones -> Cambiar el número de versiones arriba
      }
	  Serial.print("\nRespuesta Correcta:\t");
      Serial.println(ans_correct);
      break;
    
    //Nivel 2 (sin hacer)
    
    case(2):
      versiones = 0;
      vers = random(1, versiones+1);
      Serial.print("Version\t");
      Serial.println(vers);
      
      segundos_prueba = 60;
      
      switch(vers){
        
        //Prueba 4.2.1
        case(1):
		  ans_correct = "gato5perro";
          somo14d.play_complete(enun_prueba121);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 4.2.2
		case(2):
		  ans_correct = "1vaca3";
          somo14d.play_complete(enun_prueba122);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 4.2.3
		case(3):
		  ans_correct = "1356";
          somo14d.play_complete(enun_prueba123);
          somo14d.play_complete(bocina_empezar);
          break;
          
          //Se pueden añadir futuras versiones -> Cambiar el número de versiones arriba
      }
	  Serial.print("\nRespuesta Correcta:\t");
      Serial.println(ans_correct);
      break;
	  
	  //Nivel 3 (sin hacer)
    
    case(3):
      versiones = 0;
      vers = random(1, versiones+1);
      Serial.print("Version\t");
      Serial.println(vers);
      
      segundos_prueba = 75;
      
      switch(vers){
        
        //Prueba 4.3.1
        case(1):
		  ans_correct = "163";
          somo14d.play_complete(enun_prueba131);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 4.3.2
		case(2):
		  ans_correct = "23perro56";
          somo14d.play_complete(enun_prueba132);
          somo14d.play_complete(bocina_empezar);
          break;
          
          //Se pueden añadir futuras versiones -> Cambiar el número de versiones arriba
      }
	  Serial.print("\nRespuesta Correcta:\t");
      Serial.println(ans_correct);
      break;
	  
	  //Nivel 4 (sin hacer)
    
    case(4):
      versiones = 0;
      vers = random(1, versiones+1);
      Serial.print("Version\t");
      Serial.println(vers);
      
      segundos_prueba = 75;
      
      switch(vers){
        
        //Prueba 4.4.1
        case(1):
		  ans_correct = "perro35oveja4";
          somo14d.play_complete(enun_prueba141);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 4.4.2
		case(2):
		  ans_correct = "5421";
          somo14d.play_complete(enun_prueba142);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 4.4.3
		case(3):
		  ans_correct = "1ovejavaca3";
          somo14d.play_complete(enun_prueba143);
          somo14d.play_complete(bocina_empezar);
          break;
          
          //Se pueden añadir futuras versiones -> Cambiar el número de versiones arriba
      }
	  Serial.print("\nRespuesta Correcta:\t");
      Serial.println(ans_correct);
      break;
	  
	  //Nivel 5
    
    case(5):
      versiones = 1;
      vers = random(1, versiones+1);
      Serial.print("Version\t");
      Serial.println(vers);
      
      segundos_prueba = 90;
      
      switch(vers){
        
        //Prueba 4.5.1
        case(1):
		  ans_correct = "165934";
          somo14d.play_complete(enun_prueba151);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 4.5.2 (sin hacer)
		case(2):
		  ans_correct = "61354";
          somo14d.play_complete(enun_prueba152);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 4.5.3 (sin hacer)
		case(3):
		  ans_correct = "342516";
          somo14d.play_complete(enun_prueba153);
          somo14d.play_complete(bocina_empezar);
          break;
          
          //Se pueden añadir futuras versiones -> Cambiar el número de versiones arriba
      }
	  Serial.print("\nRespuesta Correcta:\t");
      Serial.println(ans_correct);
      break;
   }
}

void Prueba4::realizacion_prueba(){
  
  uOLED uoled;
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
  unsigned long start_time = millis();
  
  do{
     segundos = uoled.cuenta_atras(segundos_prueba, start_time); //CÓMO METER LOS SEGUNDOS_PRUEBA Y LA LONG_MAXIMA
     if (segundos < 15) somo14d.play_complete(beep);
     //Leer la respuesta del XBEE
     //Que se vea en la pantalla
	 while (Serial.available()) {
		 b = Serial.read();
		 ans_juego += b; 
	 }	 
	 Serial.println(ans_juego);
	 Serial.flush();
	 if (ans_juego == ans_correct) respuesta = 1;
    } while (segundos > 0 && respuesta == 0); //&& /*XBEE != Respuesta correcta && length(XBEE)<long_maxima)*/)
}

int Prueba4::feedback_prueba(int puntuacion, int ganar_puntos, int perder_puntos){
	
  uOLED uoled;
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
  pinMode(led_verde, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  
			if (respuesta == 1){
				puntuacion = puntuacion + ganar_puntos;
				digitalWrite(led_verde, HIGH);
				if ((segundos_prueba-segundos) < 0.4*segundos_prueba) somo14d.play_complete(genial_p1);
				else if (segundos < 15) somo14d.play_complete(bien_p1);
				else somo14d.play_complete(muybien_p1);
				somo14d.play_complete(ganar_puntoss);
				uoled.suma(ganar_puntos);		
                delay(1500);	
			}
			
			else {
				puntuacion = puntuacion - perder_puntos;
				if(puntuacion < 0) puntuacion = 0;
				digitalWrite(led_rojo, HIGH);
				if (segundos == 0) {
					somo14d.play_complete(mal_tiempo);
				}
				else {
					somo14d.play_complete(mal_p1);
				}
				somo14d.play_complete(perder_puntoss);
				uoled.resta(perder_puntos);
				delay(1500);
			}
	
	somo14d.play(puntuacionn);
	uoled.puntuacion(puntuacion);
    delay(4500);
	
	return puntuacion;
}