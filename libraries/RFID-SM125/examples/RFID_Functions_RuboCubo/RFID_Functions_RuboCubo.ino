#include "SM125_Functions.h"
#include <Wire.h>
#include "SM125.h"

SM125_fun sm125_fun;
long code = 0;

void setup() {
  
  Serial.begin(9600);

}

void loop() {
  
  code = sm125_fun.identification();
  Serial.println(code);
  if (code!= 0) {
    
    String str_code (code);
    char ch_code[7];
    str_code.toCharArray(ch_code, 7);
      
    Serial.print("\nPrueba \t");
    Serial.println(ch_code[0]);
    Serial.print("Nivel \t");
    Serial.println(ch_code[1]);
    Serial.print("\nPuntos a ganar \t");
    Serial.println(ch_code[2]);
    Serial.print("Puntos a perder \t");
    Serial.println(ch_code[3]);
    Serial.print("Bateria a perder \t");
    Serial.println(ch_code[4]);
    Serial.print("\nBateria a ganar \t");
    Serial.println(ch_code[5]);
    delay(3000);
   }
  delay(1000);
}
