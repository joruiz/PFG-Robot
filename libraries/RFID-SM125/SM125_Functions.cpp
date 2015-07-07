#include "SM125_Functions.h"
#include "Wire.h"
#include "SM125.h"

long SM125_fun::identification(){
 
  #define SM125_ADDRESS 0x46

  SM125 sm125;
  String tagId;
  
  sm125.begin(SM125_ADDRESS);
  
  tagId = sm125.readTag();
  
  if (!tagId.equals("")) {
    Serial.println("Tag leido: " + tagId);
    if(tagId.equals("0B42A392")){
      code = 103010; //Code structure: 10p+3p-1b-1b+0 //Prueba, nivel, +puntos, -puntos, -bateria
     }
	else if(tagId.equals("0B427E26")){
      code = 113110; //Code structure: 11p+3p-1b-1b+0
     }
    else if(tagId.equals("0B427979")){
      code = 124210; //Code structure: 12p+4p-2b-1b+0
     }
	else if(tagId.equals("0B42794B")){
      code = 135220; //Code structure: 13p+5p-2b-2b+0
     }
	else if(tagId.equals("0B427BD2")){
      code = 146320; //Code structure: 14p+6p-3b-2b+0
     }
	else if(tagId.equals("0B427FE7")){
      code = 158330; //Code structure: 15p+8p-3b-3b+0
     }
	else if(tagId.equals("0B42A9C9")){
      code = 213110; //Code structure: 21p+3p-1b-1b+0	  
     }
	else if(tagId.equals("0B427DE8")){
      code = 224210; //Code structure: 22p+4p-2b-1b+0
     }
	else if(tagId.equals("0B42799A")){
      code = 235220; //Code structure: 23p+5p-2b-2b+0
     }
	else if(tagId.equals("PONERALGO")){
      code = 246320; //Code structure: 24p+6p-3b-2b+0
     }
	else if(tagId.equals("0B428767")){
      code = 257520; //Code structure: 25p+8p-5b-2b+0
     }
	else if(tagId.equals("0B427DA5")){
      code = 313110; //Code structure: 31p+3p-1b-1b+0
     }
	else if(tagId.equals("0B427FF8")){
      code = 336110; //Code structure: 33p+6p-1b-1b+0
     }
	else if(tagId.equals("0B42799D")){
      code = 613110; //Code structure: 61p+3p-1b-1b+0
     }

	
   }
  else {
    Serial.println("No Tag");
    code = 0;
  }
  
  delay(500);
  
  return code;
  
}
