#include "Prueba1.h"
#include "SOMO14D.h"
#include"uOLED_Functions.h"
#include "Hardware.h"
#include "Protocol.h"

Prueba1::Prueba1(){

}

void Prueba1::sendMessage(){
 
 Serial.println("Mensaje de Prueba1");
 
}

void Prueba1::presentacion_prueba(){
  
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
  somo14d.play_complete(sonido_intro);
  somo14d.play_complete(tit_prueba1);
  
}

void Prueba1::explicacion_prueba(){
  
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
  somo14d.play_complete(exp_prueba1);

}

void Prueba1::enunciado_prueba(int nivel){
  
  nivel_prueba = nivel;
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
  switch(nivel){
    
    //Nivel 0
	
	case(0):
      versiones = 1;
      vers = random(1, versiones+1);
      Serial.print("\nVersion\t");
      Serial.println(vers);
      
	  segundos_prueba = 50;
	  
	  switch(vers){
        
        //Versión Prueba
        case(1):
		  ans_correct = "1@0|5@0";
          somo14d.play_complete(enun_prueba110);
          somo14d.play_complete(bocina_empezar);
          break;
      }
	  Serial.print("\nRespuesta Correcta:\t");
      Serial.println(ans_correct);
	  break;
	
	//Nivel 1
    
    case(1):
      versiones = 3;
      vers = random(1, versiones+1);
      Serial.print("Version\t");
      Serial.println(vers);
      
      segundos_prueba = 60;
      
      switch(vers){
        
        //Prueba 1.1.1
        case(1):
		  ans_correct = "42perro";
		  somo14d.play_complete(orden_directo_prueba1);
          somo14d.play_complete(enun_prueba111);
          somo14d.play_complete(bocina_empezar);
          break;
		
        //Prueba 1.1.2		
		case(2):
		  ans_correct = "4perrogato5";
		  somo14d.play_complete(orden_directo_prueba1);
          somo14d.play_complete(enun_prueba112);
          somo14d.play_complete(bocina_empezar);
          break;
		
        //Prueba 1.1.3		
		case(3):
		  ans_correct = "134";
		  somo14d.play_complete(orden_directo_prueba1);
          somo14d.play_complete(enun_prueba113);
          somo14d.play_complete(bocina_empezar);
          break;
          
        //Se pueden añadir futuras versiones -> Cambiar el número de versiones arriba
      }
	  Serial.print("\nRespuesta Correcta:\t");
      Serial.println(ans_correct);
      break;
    
    //Nivel 2
    
    case(2):
      versiones = 3;
      vers = random(1, versiones+1);
      Serial.print("Version\t");
      Serial.println(vers);
      
      segundos_prueba = 60;
      
      switch(vers){
        
        //Prueba 1.2.1
        case(1):
		  ans_correct = "gato5perro";
		  somo14d.play_complete(orden_inverso_prueba1);
          somo14d.play_complete(enun_prueba121);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 1.2.2
		case(2):
		  ans_correct = "1vaca3";
		  somo14d.play_complete(orden_inverso_prueba1);
          somo14d.play_complete(enun_prueba122);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 1.2.3
		case(3):
		  ans_correct = "1356";
		  somo14d.play_complete(orden_directo_prueba1);
          somo14d.play_complete(enun_prueba123);
          somo14d.play_complete(bocina_empezar);
          break;
          
          //Se pueden añadir futuras versiones -> Cambiar el número de versiones arriba
      }
	  Serial.print("\nRespuesta Correcta:\t");
      Serial.println(ans_correct);
      break;
	  
	  //Nivel 3
    
    case(3):
      versiones = 2;
      vers = random(1, versiones+1);
      Serial.print("Version\t");
      Serial.println(vers);
      
      segundos_prueba = 75;
      
      switch(vers){
        
        //Prueba 1.3.1
        case(1):
		  ans_correct = "163";
		  somo14d.play_complete(orden_numeros_prueba1);
          somo14d.play_complete(enun_prueba131);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 1.3.2
		case(2):
		  ans_correct = "23perro56";
		  somo14d.play_complete(orden_directo_prueba1);
          somo14d.play_complete(enun_prueba132);
          somo14d.play_complete(bocina_empezar);
          break;
          
          //Se pueden añadir futuras versiones -> Cambiar el número de versiones arriba
      }
	  Serial.print("\nRespuesta Correcta:\t");
      Serial.println(ans_correct);
      break;
	  
	  //Nivel 4
    
    case(4):
      versiones = 3;
      vers = random(1, versiones+1);
      Serial.print("Version\t");
      Serial.println(vers);
      
      segundos_prueba = 75;
      
      switch(vers){
        
        //Prueba 1.4.1
        case(1):
		  ans_correct = "perro35oveja4";
		  somo14d.play_complete(orden_directo_prueba1);
          somo14d.play_complete(enun_prueba141);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 1.4.2
		case(2):
		  ans_correct = "5421";
		  somo14d.play_complete(orden_inverso_prueba1);
          somo14d.play_complete(enun_prueba142);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 1.4.3
		case(3):
		  ans_correct = "1ovejavaca3";
		  somo14d.play_complete(orden_inverso_prueba1);
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
      versiones = 3;
      vers = random(1, versiones+1);
      Serial.print("Version\t");
      Serial.println(vers);
      
      segundos_prueba = 90;
      
      switch(vers){
        
        //Prueba 1.5.1
        case(1):
		  ans_correct = "165934";
		  somo14d.play_complete(orden_directo_prueba1);
          somo14d.play_complete(enun_prueba151);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 1.5.2
		case(2):
		  ans_correct = "61354";
		  somo14d.play_complete(orden_inverso_prueba1);
          somo14d.play_complete(enun_prueba152);
          somo14d.play_complete(bocina_empezar);
          break;
		
		//Prueba 1.5.3
		case(3):
		  ans_correct = "342516";
		  somo14d.play_complete(orden_inverso_prueba1);
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

void Prueba1::realizacion_prueba(){
  
  uOLED uoled;
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  
  unsigned long start_time = millis();
  
  do{
     segundos = uoled.cuenta_atras(segundos_prueba, start_time); //CÓMO METER LOS SEGUNDOS_PRUEBA Y LA LONG_MAXIMA
     if (segundos < 15) somo14d.play_complete(beep);
     //Leer la respuesta del XBEE
     //Que se vea en la pantalla
	 
	 String dataReceived = "";
  
     // if (OK6 == 1 && message.equals("ACK_OK 6")){
		// OK6 = 0;
		// Serial3.println("SEQUENCE?\r");
		// Serial.println("SEQUENCE?\r");
		
		// int t = 0;
		
		// while(t == 0){
			// if(Serial3.available()){
				// while (Serial3.available()) {
					// char data = Serial3.read();
					// dataReceived += data;
				// }
			// }
			// t = 1;
		// }
			
     // }
	 
	 if((millis()-tiempo)>3000){
		 OK5 = 0;
		 tiempo = millis();
		 Serial3.println("SEQUENCE?\r");
		 Serial.println("SEQUENCE?\r");
	 }
     while (Serial3.available()) {
       char data = Serial3.read();
       dataReceived += data;
     }
		 
     //check if there is any message (it must be finish with END_COMMAND)
     int index = dataReceived.indexOf(END_COMMAND);
     if (index != -1) {
       //get message, execute it and remove from receive bytes
       String message = dataReceived.substring(0, index);
       dataReceived = dataReceived.substring(index + 1);
       Serial.println("Msg. Received: " + message);  
       //get command and execute the concrete action
       String command = getCommand(message);
       Serial.println("Command: " + command);
       if (command.equals("SEQUENCE")) {
         String parameters = getParameters(message);
         Serial.println("Parameters: " + parameters);
		 if (parameters.equals(ans_correct)) respuesta = 1;
         Serial.write(END_COMMAND);
        }
    }
	
	//if(message.equals("ACK_OK 6")) OK6 = 1;
	//if (command.equals("LEADER?")) OK5 = 0;
  
    //Serial.println(parameters);
    //Serial.flush();
	
	
	delay(20);
	
	 // while (Serial.available() != 0) {
		 // b = Serial.read();
		 // ans_juego += b; 
	 // }	

	 
	 // Serial.println(ans_juego);
	 // Serial.flush();
	 // if (ans_juego == ans_correct) respuesta = 1;
    } while (segundos > 0 && respuesta == 0); //&& /*XBEE != Respuesta correcta && length(XBEE)<long_maxima)*/)
}

int Prueba1::feedback_prueba(int puntuacion, int ganar_puntos, int perder_puntos){
	
  uOLED uoled;
  SOMO14D somo14d;
  somo14d.begin(51, 52, 53); //Clckpin, datapin, reset
  // SoftwareSerial BT (10,11)
  // BT.begin(9600);
  
  pinMode(led_verde, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  
	if (nivel_prueba == 0){
		if (respuesta == 0) {
			puntuacion = puntuacion - perder_puntos;
			digitalWrite(led_rojo, HIGH);
			if (segundos == 0) {
					somo14d.play_complete(mal_tiempo);
				}
            somo14d.play_complete(mal0);
		}
		else {
			puntuacion = puntuacion + ganar_puntos;
			digitalWrite(led_verde, HIGH);
            somo14d.play_complete(bien0);
            uoled.suma(ganar_puntos);
			delay(1500);
            //Hay que crear bien las variables. Esto solo de prueba
		}
	}
    else {
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
	}	
	
    // BT.println("\n");
    // BT.println("Prueba 1");
	// BT.print("Nivel: ");
    // BT.println(nivel_prueba);	
	// BT.print("Respuestas correctas: ");
	// if (respuesta == 1) BT.println("Respuestas correctas: Sí");
	// else BT.println("Respuestas correctas: No");
	// BT.print("Tiempo durado: ");
	// int enviar = segundos_prueba-segundos;	
	// BT.println(enviar);
	// BT.print("Puntuacion: ");
	// BT.println(puntuacion);
	
	
	somo14d.play(puntuacionn);
	uoled.puntuacion(puntuacion);
    delay(4500);
	
	return puntuacion;
}