//Librerías que se van a utilizar
#include "SoftwareSerial.h"
#include "BarGraph.h"
#include "Shiftduino.h"
#include "PololuLedStrip.h"
#include "LedStrip_Functions.h"
#include "Goldelox_const4D.h"
#include "Goldelox_Serial_4DLib.h"
#include "uOLED_Functions.h"
#include "Platform.h"
#include "EasyVR.h"
#include "EasyVR_Functions.h"
#include "SOMO14D.h"
#include "Wire.h"
#include "SM125.h"
#include "SM125_Functions.h"
#include "Hardware.h"
#include "Protocol.h"
#include "Prueba.h"
#include "Prueba1.h"
#include "Prueba2.h"
#include "Prueba3.h"
#include "Prueba6.h"
#include "Prueba9.h"

//Definición de estados
#define bienvenida 0
#define movimiento 1
#define identificacion 2
#define juego 3

//Definición de estados del estado "juego"
#define seleccion_prueba0 0
#define explicacion_prueba0 1
#define enunciado_prueba0 2
#define realizacion_prueba0 3
#define feedback_prueba0 4

//Definición de los objetos
SOMO14D somo14d;
LedStrip_fun ledstrip_fun;
SM125_fun sm125_fun;
BarGraph bg;
EasyVR_fun easyvr_fun;
uOLED uoled;
Shiftduino sd(40, 41, 42, 2); //Datapin, Clockpin, Latchpin
Prueba *miPrueba;

//Definición de las constantes de SOMO14D
const int bienvenido = 0;
const int colocar_salida = 1;
const int instrucciones1 = 2;
const int instrucciones2 = 3;
const int instrucciones3 = 4;
const int instrucciones4 = 5;
const int instrucciones5 = 6;
const int instrucciones6 = 7;
const int prueba_ejemplo = 8;
const int beep = 9;
const int repetir_instrucciones = 10;
const int adios = 11;
const int tresdosuno = 12;
const int bien0 = 13;
const int mal0 = 14;
const int escuchar_instrucciones = 15;
const int enun_prueba110 = 16;
const int sonido_intro = 17;
const int no_oir = 18;
const int no_entender = 19;
const int tit_prueba1 = 21;
const int exp_prueba1 = 22;
const int enun_prueba111 = 23;
const int enun_prueba112 = 24;
const int enun_prueba121 = 25;
const int enun_prueba122 = 26;
const int puntuacionn = 30;
const int bateria_baja = 33;
const int listo_para_jugar = 40;
const int repetir_instrucciones_comment = 50;
const int avanzar_casilla = 60;
const int no_bateria = 70;
const int juguemos = 80;
const int elegir_camino = 100;
const int motor = 150;
const int bienvenido2 = 160;
const int silencio = 170;


//Otras variables
int estado;
int estado_juego;
long code;
int led_verde = 9;
int led_rojo = 8;
int ans1; //Respuesta vocal 1
int ans2; //Respuesta vocal 2
int ans_juego; //Respuesta del juego (para probar si funciona o no)
int prueba;
int nivel;
int vers;
int puntuacion = 0;
int ganar_puntos = 3;
int perder_puntos;
int ganar_bateria;
int perder_bateria = 1;
unsigned long espera1;
unsigned long espera2 = 13000;
boolean bateria[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//Variables del algortimo PD
#define derder 37
#define der 36
#define izq 35
#define izqizq 34
#define PWM_DERECHA  5 //Gira a la derecha
#define PWM_IZQUIERDA  4 //Gira a la izquierda
int error = 0;
int error_antes = 0;
int var;
int m_derecha;
int m_izquierda;
int kp = 10;
int kd = 2;
int vel = 70;
char *mensaje;
int uno;
int dos;
int tres;
int cuatro;
int camino = 0;
int elegir;


void setup() {

  Serial.begin(9600);
  Serial3.begin(9600);
  Serial3.flush();
     
  estado = movimiento;
  
  Goldelox_Serial_4DLib Display(&Serial2, 31); // Reset pin
  Serial2.begin(9600);

  somo14d.begin(51, 52, 53);
  //somo14d.play_complete(beep);

  pinMode(led_verde, OUTPUT);
  pinMode(led_rojo, OUTPUT);

  rgb_color NONEE;
  NONEE.red = 0;
  NONEE.green = 0;
  NONEE.blue = 0;

  ledstrip_fun.matrix_general(NONEE, 200);
  
  bg.begin();
  bg.addEnergy(10);
  boolean *output = bg.getOutput();
  for (int i = 0; i < 10; i++)
    bateria[i] = output[i];
  sd.setPins(bateria);
  
  somo14d.play_complete(silencio);
  Serial.println("Estado bienvenida");
  somo14d.play(bienvenido2);
  delay(500);
  ledstrip_fun.matrix_welcome();
  uoled.presentacion();
  delay(1500);
  while(somo14d.getState() == HIGH) delay(200);  
  code = 0;
  
  somo14d.play_complete(motor);
}

void loop() {
  
  rgb_color GREENN;
  GREENN.red = 0;
  GREENN.green = 255;
  GREENN.blue = 0;
  
  rgb_color BLUEE;
  BLUEE.red = 0;
  BLUEE.green = 0;
  BLUEE.blue = 255;
  
  rgb_color REDD;
  REDD.red = 255;
  REDD.green = 0;
  REDD.blue = 0;
  
  rgb_color PURPLEE;
  PURPLEE.red = 255;
  PURPLEE.green = 0;
  PURPLEE.blue = 255;
  
  rgb_color YELLOWW;
  YELLOWW.red = 255;
  YELLOWW.green = 255;
  YELLOWW.blue = 0;
  
  rgb_color WHITEE;
  WHITEE.red = 255;
  WHITEE.green = 255;
  WHITEE.blue = 255;
  
  rgb_color NONEE;
  NONEE.red = 0;
  NONEE.green = 0;
  NONEE.blue = 0;
  
  switch(estado){
      case(bienvenida):
        Serial.println("Estado bienvenida");
        somo14d.play(bienvenido);
        delay(500);
        ledstrip_fun.matrix_welcome();
        uoled.presentacion();
        while(somo14d.getState() == HIGH) delay(200);  
        code = 0;
        while (code != 103010) { //Más que esté sobre las líneas negras
          espera1 = millis();
          code = sm125_fun.identification();    
          if (abs(espera1-espera2) >= 14000){
            Serial.println("El robot no esta situado en la casilla de salida");
            somo14d.play(colocar_salida);
            espera2 = espera1;
          }
        }
        
        {String str_code (code);
        char ch_code[7];
        str_code.toCharArray(ch_code, 7);
        
        prueba = ch_code[0]-48;
        nivel = ch_code[1]-48;
        ganar_puntos = ch_code[2]-48;
        perder_puntos = ch_code[3]-48;
        perder_bateria = ch_code[4]-48;
        ganar_bateria = ch_code[5]-48;}
        
        uoled.prueba(prueba, nivel);
        
        Serial.print("\nPrueba \t");
        Serial.println(prueba);
        Serial.print("Nivel \t");
        Serial.println(nivel);
        Serial.print("\nPuntos a ganar \t");
        Serial.println(ganar_puntos);
        Serial.print("Puntos a perder ");
        Serial.println(perder_puntos);
        Serial.print("Bateria a perder ");
        Serial.println(perder_bateria);
        Serial.print("Bateria a ganar ");
        Serial.println(ganar_bateria);
        
        do {
          ans2 = 0;
          somo14d.play_complete(instrucciones1);
          somo14d.play_complete(instrucciones2);
          digitalWrite(led_verde, HIGH);
          ledstrip_fun.matrix_general(GREENN, 1500); 
          somo14d.play_complete(instrucciones3);
          digitalWrite(led_verde, LOW);
          digitalWrite(led_rojo, HIGH);
          ledstrip_fun.matrix_general(REDD, 1500);
          digitalWrite(led_rojo, LOW);
          ledstrip_fun.matrix_general(NONEE, 200);
          somo14d.play_complete(instrucciones4);
          for (int i = 0; i < 10; i++){
            bg.subEnergy(1);
            boolean *output = bg.getOutput();
          for (int i = 0; i < 10; i++) bateria[i] = output[i];
          sd.setPins(bateria);
          delay(150);
          }
          somo14d.play_complete(instrucciones5);
          for (int i = 0; i < 10; i++){
            bg.addEnergy(1);
            boolean *output = bg.getOutput();
          for (int i = 0; i < 10; i++) bateria[i] = output[i];
          sd.setPins(bateria);
          delay(100);
          }
          somo14d.play_complete(instrucciones6);  
          somo14d.play_complete(beep);
          ans1 = easyvr_fun.recognize(1, 4);
          if (ans1 == 2) {
            somo14d.play_complete(repetir_instrucciones);
            somo14d.play_complete(beep);
            
            ans2 = easyvr_fun.recognize(1, 4);
          }
          if (ans2 == 2) {
            somo14d.play_complete(adios);//Meter algo para que termine
            break;
          }
        } while (ans2 == 1);
        
        ans1 = 0;
        somo14d.play_complete(prueba_ejemplo);
        estado = juego;
        estado_juego = seleccion_prueba0;
        
      break;
      
      
      case(movimiento):
        Serial.println("Estado movimiento");
                
        // Incluir la función de movimiento y los sensores
          uno = 0;
          dos = 0;
          tres = 0;
          cuatro = 0;
          elegir = 0;
          
          if (digitalRead(derder)==HIGH) uno = 1;
          if (digitalRead(der)==HIGH) dos = 1;  
          if (digitalRead(izq)==HIGH) tres = 1;  
          if (digitalRead(izqizq)==HIGH) cuatro = 1;
            
          if (uno == 0 && dos == 1 && tres == 1 && cuatro == 0) {
              error = 0;
              mensaje = "recto";
              }
          else if (uno == 1 && dos == 0 && tres == 0 && cuatro == 1) {
              error = 0;
              mensaje = "stop";
              estado = identificacion;
              code = 0;
              }
          else if (uno == 0 && dos == 0 && tres == 0 && cuatro == 0) {
              error = -2;
              mensaje = "gira";
              }
              
          else if (uno == 0 && dos == 0 && cuatro == 1){
            error = 1;
            mensaje = "derecha";
            if (tres == 0){
              error = 4;
              mensaje = "muy derecha";
              }
            }
        
          else if (cuatro == 0 && tres == 0 && uno == 1){
            error = -1;
            mensaje = "izquierda";
            if (dos == 0){
              error = -4;
              mensaje = "muy izquierda";
              }
            }
          else if(uno == 1 && dos == 1 && tres == 1 && cuatro == 1){
            m_derecha = 0;
            m_izquierda = 0;
            analogWrite(PWM_DERECHA, m_derecha);
            analogWrite(PWM_IZQUIERDA, m_izquierda);
            Serial.println("Stop");
            if (elegir == 0){
              somo14d.play_complete(elegir_camino);
              elegir = 1;
            }
            if (elegir == 0){
              somo14d.play_complete(elegir_camino);
              elegir = 1;
            }
            somo14d.play_complete(beep);
            camino = 0;
            camino = easyvr_fun.recognize(2,4);
            Serial.println(camino);
            if (camino == 4){
              m_derecha = 200;
              m_izquierda = 0;
              analogWrite(PWM_DERECHA, m_derecha);
              analogWrite(PWM_IZQUIERDA, m_izquierda);
              delay(750);
        //      analogWrite(PWM_DERECHA, 0);
        //      analogWrite(PWM_IZQUIERDA, 0);
        //      delay(50000);
              }
            else if(camino == 5){
              m_derecha = 0;
              m_izquierda = 200;
              analogWrite(PWM_DERECHA, m_derecha);
              analogWrite(PWM_IZQUIERDA, m_izquierda);
              delay(750);
              }
            }
             
            else error = 0;
            
            if (mensaje=="stop"){
              var = 0;
              m_derecha = 0;
              m_izquierda = 0;
            }
              
            else { 
              var = kp*error + kd*(error-error_antes);
              m_derecha = vel + var;
              m_izquierda = vel - var;
            }
            
            
            analogWrite(PWM_DERECHA, m_derecha);
            analogWrite(PWM_IZQUIERDA, m_izquierda);
            error_antes = error;
            Serial.print(uno);
            Serial.print("   ");
            Serial.print(dos);
            Serial.print("   ");
            Serial.print(tres);
            Serial.print("   ");
            Serial.print(cuatro);
            Serial.println("");
            Serial.println("");
            
            Serial.println(var);
            Serial.print("Motor derecha: ");
            Serial.println(m_derecha);
            Serial.print("Motor izquierda: ");
            Serial.println(m_izquierda);
        
            delay(10);
      break;
      
      
      case(identificacion):
        Serial.println("Estado identificacion");
        //delay(3000);
        code = 0;
        do {
            code = sm125_fun.identification();
           } while (code == 0);
        // code = 613110;
        Serial.println(code);

           
        {String str_code (code);
        char ch_code[7];
        str_code.toCharArray(ch_code, 7);
        
        prueba = ch_code[0]-48;
        nivel = ch_code[1]-48;
        ganar_puntos = ch_code[2]-48;
        perder_puntos = ch_code[3]-48;
        perder_bateria = ch_code[4]-48;
        ganar_bateria = ch_code[5]-48;}
        
        uoled.prueba(prueba, nivel);
        
        Serial.print("\nPrueba \t");
        Serial.println(prueba);
        Serial.print("Nivel \t");
        Serial.println(nivel);
        Serial.print("\nPuntos a ganar \t");
        Serial.println(ganar_puntos);
        Serial.print("Puntos a perder ");
        Serial.println(perder_puntos);
        Serial.print("Bateria a perder ");
        Serial.println(perder_bateria);
        Serial.print("Bateria a ganar ");
        Serial.println(ganar_bateria);
        
        estado = juego;
        estado_juego = seleccion_prueba0;

        break;      
      
      case(juego):
        Serial.println("Estado juego");
        switch(estado_juego) {
          case(seleccion_prueba0):       
            switch(prueba){
              
              case(1):
                miPrueba = new Prueba1();
              break;
              
              case(2):
                miPrueba = new Prueba2();
              break;
              
              case(3):
                miPrueba = new Prueba3();
              break;
              
              case(6):
                miPrueba = new Prueba6();
              break;
              
              case(9):
                miPrueba = new Prueba9();
              break;
            }
            estado_juego = explicacion_prueba0;
            break;
           
          case(explicacion_prueba0):
            miPrueba->presentacion_prueba(); delay(20);
            somo14d.play_complete(escuchar_instrucciones); delay(20);
            somo14d.play_complete(beep);
            ans1 = easyvr_fun.recognize(1, 4);
            if (ans1 == 2) somo14d.play_complete(juguemos);
            else {
              do{
              miPrueba->explicacion_prueba();
              somo14d.play_complete(listo_para_jugar); 
              somo14d.play_complete(beep);
              ans2 = easyvr_fun.recognize(1, 4);
              if (ans2 == 2) somo14d.play_complete(repetir_instrucciones_comment); //Entonces te volveré a repetir las instrucciones
              } while (ans2 != 1);
            }
            estado_juego = enunciado_prueba0;
            break;
            
          case(enunciado_prueba0):
            miPrueba->enunciado_prueba(nivel);
            estado_juego = realizacion_prueba0;
            break;
          
          case(realizacion_prueba0):
            miPrueba->realizacion_prueba();
            estado_juego = feedback_prueba0;
            break;
            
          case (feedback_prueba0):
            puntuacion = miPrueba->feedback_prueba(puntuacion, ganar_puntos, perder_puntos);
            
            digitalWrite(led_verde, LOW);
            digitalWrite(led_rojo, LOW);
            
            bg.addEnergy(ganar_bateria);
            bg.subEnergy(perder_bateria);
            {boolean *output = bg.getOutput();
            for (int i = 0; i < 10; i++)
              bateria[i] = output[i];}
            sd.setPins(bateria);
            
            if (bg.getEnergy() <= 4 && bg.getEnergy() > 0) somo14d.play_complete(bateria_baja); //Avisar de que tiene poca batería
            
            if (bg.getEnergy() == 0){            
              somo14d.play_complete(no_bateria);
              puntuacion = puntuacion - 10;
              if (puntuacion < 0) puntuacion = 0;
              uoled.resta(10);
  	      delay(1500);
              bg.addEnergy(5);
              boolean *output = bg.getOutput();
              for (int i = 0; i < 10; i++)
              bateria[i] = output[i];
              sd.setPins(bateria);
              somo14d.play(puntuacionn);
  	      uoled.puntuacion(puntuacion);
              delay(4500);
            }
            somo14d.play_complete(avanzar_casilla);
            somo14d.play_complete(motor);
            analogWrite(PWM_DERECHA, 255);
            analogWrite(PWM_IZQUIERDA, 255);
            delay(1000);  
            estado = movimiento;
            code = 0;
            break;
     }          
     break;  
  }
}
