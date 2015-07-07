#include <SoftwareSerial.h>
SoftwareSerial DisplaySerial(2,3) ; // pin 2 = TX of display, pin3 = RX

#include "Goldelox_Serial_4DLib.h"
#include "Goldelox_const4D.h"

Goldelox_Serial_4DLib Display(&DisplaySerial, 5); //Reset pin

void setup()
{
 DisplaySerial.begin(9600);
}

void loop()
{
  Display.TimeLimit4D   = 3000 ; // 2 second timeout on all commands
  
  Display.gfx_Cls();
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(WHITE);
  Display.txt_FontID(SYSTEM);
  Display.txt_MoveCursor(3, 2);
  Display.txt_Height(4);
  Display.txt_Width(2);
  Display.putstr("PUNTUACION");
  
  char puntuacion[] = "300";
  
  Display.txt_MoveCursor(2, 3);
  Display.txt_Attributes(BOLD);
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(WHITE);
  Display.txt_FontID(3);
  Display.txt_Height(5);
  Display.txt_Width(3); 
  Display.putstr(puntuacion);
  
  delay(5000);
}

