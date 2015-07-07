#include "Xbee.h"
#include "Hardware.h"
#include "Protocol.h"


String Xbee::executeSequence() {
  
  String dataReceived = "";
  
  Serial.begin(9600);
  Serial3.begin(9600);
  Serial.flush();
  Serial3.flush();
  
  Serial3.println("SEQUENCE?\r");
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
      Serial.write(END_COMMAND);
      return parameters;
    }
  }
  
  Serial3.end();
}

String Xbee::executeShake() {
  
  String dataReceived = "";
  
  Serial.begin(9600);
  Serial3.begin(9600);
  Serial.flush();
  Serial3.flush();
  
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
    String command = getCommand(message);
    Serial.println("Command: " + command);
    if (command.equals("SHAKE_ON")) {
      String parameters = getParameters(message);
      if (numberOfParameters(parameters) == 1)
        byte shake_id = getParameter(parameters, 0).toInt();
      Serial.println("Parameters: " + parameters);
      Serial.write(END_COMMAND);
	  return "";
      }
	}	

  else
	return "";
  //Serial3.end();
}
