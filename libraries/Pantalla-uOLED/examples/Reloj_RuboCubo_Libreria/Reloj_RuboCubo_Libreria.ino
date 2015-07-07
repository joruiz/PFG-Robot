#include <SoftwareSerial.h>
#include "Goldelox_Serial_4DLib.h"
#include "Goldelox_const4D.h"
#include "uOLED_Functions.h"

Goldelox_Serial_4DLib Display(&Serial2, 31); //Reset pin

int segundos_prueba = 120;
unsigned long start_time;
int segundos2 = 121;
uOLED uoled;

void setup()
{
 delay(3000);
 start_time = millis();
 Serial2.begin(9600);
}

void loop()
{
  uoled.cuenta_atras(segundos_prueba,start_time);
}

