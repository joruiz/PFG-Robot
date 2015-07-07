#include "uOLED_Functions.h"
#include "SoftwareSerial.h"
#include "Goldelox_Serial_4DLib.h"
#include "Goldelox_const4D.h"

void uOLED::presentacion(){
	
  Goldelox_Serial_4DLib Display(&Serial2, 31);
  Serial2.begin(9600);
  
  Display.gfx_Cls();
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(WHITE);
  Display.txt_FontID(SYSTEM);
  Display.txt_MoveCursor(2, 7);
  Display.txt_Height(4);
  Display.txt_Width(2);
  Display.putstr("HOLA");
  
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(WHITE);
  Display.txt_FontID(SYSTEM);
  Display.txt_MoveCursor(2, 2);
  Display.txt_Height(4);
  Display.txt_Width(2);
  Display.putstr("SOY ");
  
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(RED);
  Display.txt_FontID(SYSTEM);
  Display.txt_Height(4);
  Display.txt_Width(2);
  Display.putstr("R");
  
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(GREEN);
  Display.txt_FontID(SYSTEM);
  Display.txt_Height(4);
  Display.txt_Width(2);
  Display.putstr("U");
  
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(BLUE);
  Display.txt_FontID(SYSTEM);
  Display.txt_Height(4);
  Display.txt_Width(2);
  Display.putstr("B");
  
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(YELLOW);
  Display.txt_FontID(SYSTEM);
  Display.txt_Height(4);
  Display.txt_Width(2);
  Display.putstr("O");
}

void uOLED::puntuacion(int puntos){

  //DisplaySerial(Serial2);
  Goldelox_Serial_4DLib Display(&Serial2, 31); //Reset pin
  Serial2.begin(9600);
  
  Display.TimeLimit4D   = 3000; // 2 second timeout on all commands

  String punta (puntos);
  char puntuacion[5];
  punta.toCharArray(puntuacion, 5);
  
  Display.gfx_Cls();
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(WHITE);
  Display.txt_FontID(SYSTEM);
  Display.txt_MoveCursor(3, 2);
  Display.txt_Height(4);
  Display.txt_Width(2);
  Display.putstr("PUNTUACION");
  
  Display.txt_MoveCursor(2, 5);
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(WHITE);
  Display.txt_FontID(3);
  Display.txt_Height(5);
  Display.txt_Width(3); 
  Display.putstr(puntuacion); 
}

void uOLED::suma(int mas){

  Goldelox_Serial_4DLib Display(&Serial2, 31); //Reset pin
  Serial2.begin(9600);
  
  Display.TimeLimit4D   = 3000 ; // 2 second timeout on all commands

  String punta (mas);
  char suma[5];
  punta.toCharArray(suma, 5);
  
  Display.gfx_Cls();
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(GREEN);
  Display.txt_FontID(SYSTEM);
  Display.txt_MoveCursor(4, 6);
  Display.txt_Height(7);
  Display.txt_Width(4);
  Display.putstr("+");
  
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(GREEN);
  Display.txt_FontID(3);
  Display.txt_Height(7);
  Display.txt_Width(4); 
  Display.putstr(suma);
}

void uOLED::resta(int menos){

  Goldelox_Serial_4DLib Display(&Serial2, 31); //Reset pin
  Serial2.begin(9600);
  
  Display.TimeLimit4D   = 3000; // 2 second timeout on all commands

  String punta (menos);
  char resta[5];
  punta.toCharArray(resta, 5);
  
  Display.gfx_Cls();
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(RED);
  Display.txt_FontID(SYSTEM);
  Display.txt_MoveCursor(4, 4);
  Display.txt_Height(7);
  Display.txt_Width(4);
  Display.putstr("-");
  
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(RED);
  Display.txt_FontID(3);
  Display.txt_Height(7);
  Display.txt_Width(4); 
  Display.putstr(resta);
}

void uOLED::prueba(int prueba_int, int nivel_int){

  Goldelox_Serial_4DLib Display(&Serial2, 31); //Reset pin
  Serial2.begin(9600);
  
  Display.TimeLimit4D   = 3000 ; // 2 second timeout on all commands
   
  String punta (prueba_int);
  char prueba[5];
  punta.toCharArray(prueba, 5);
  
  String punta2 (nivel_int);
  char nivel[5];
  punta2.toCharArray(nivel, 5);
  
  Display.gfx_Cls();
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(WHITE);
  Display.txt_FontID(SYSTEM);
  Display.txt_MoveCursor(4, 4);
  Display.txt_Height(3);
  Display.txt_Width(2);
  Display.putstr("Prueba ");
  
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(WHITE);
  Display.txt_FontID(3);
  Display.txt_Height(3);
  Display.txt_Width(2); 
  Display.putstr(prueba);
  
  Display.txt_MoveCursor(3, 2);
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(WHITE);
  Display.txt_FontID(SYSTEM);
  Display.txt_Height(3);
  Display.txt_Width(2);
  Display.putstr("Nivel ");
  
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(WHITE);
  Display.txt_FontID(3);
  Display.txt_Height(3);
  Display.txt_Width(2); 
  Display.putstr(nivel);
}

int uOLED::cuenta_atras(int segundos_prueba, unsigned long start_time){

  Goldelox_Serial_4DLib Display(&Serial2, 31); //Reset pin
  Serial2.begin(9600);
  
  Display.TimeLimit4D   = 3000 ;
  
  segundos1 = segundos_prueba-(millis()-start_time)/1000;
  
  
  minutos = segundos1 / 60;
  segundos_mod = segundos1 - minutos*60;
  String seg(segundos_mod);
  String minu(minutos);
  seg.toCharArray(segundos_mostrar,3);
  minu.toCharArray(minutos_mostrar,2);
  
  if (segundos2-segundos1 >= 1 || r == 1){
    Display.gfx_Cls();
    Display.txt_Attributes(BOLD);
    Display.txt_BGcolour(BLACK);
    Display.txt_FGcolour(WHITE);
    Display.txt_FontID(SYSTEM);
    Display.txt_MoveCursor(2, 2);
    Display.txt_Height(4);
    Display.txt_Width(3);
    Display.putstr("TIEMPO");
    
    Display.txt_MoveCursor(2, 1);
    Display.txt_Attributes(BOLD);
    Display.txt_BGcolour(BLACK);
    Display.txt_FGcolour(WHITE);
    Display.txt_FontID(SYSTEM);
    Display.txt_Height(5);
    Display.txt_Width(4);
    Display.putstr(minutos_mostrar);
    
    Display.txt_Attributes(BOLD);
    Display.txt_BGcolour(BLACK);
    Display.txt_FGcolour(WHITE);
    Display.txt_FontID(SYSTEM);
    Display.txt_Height(5);
    Display.txt_Width(4);
    Display.putstr(":");
    
    Display.txt_Attributes(BOLD);
    Display.txt_BGcolour(BLACK);
    Display.txt_FGcolour(WHITE);
    Display.txt_FontID(3);
    Display.txt_Height(5);
    Display.txt_Width(4); 
    Display.putstr(segundos_mostrar);
    
	segundos2 = segundos1;
	r = 0;
    
    }
  
  return segundos1;
}
