#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "Arduino.h"

#define END_COMMAND  0x0D
#define COMMAND_SEP  ' '
#define PARAM_SEP    ','
#define STATE_SEP    '@'
#define CUBES_SEP    '|'
#define COUPLES_SEP  '^'
#define RELATION_SEP '-'
#define SEQUENCE_SEP '+'
#define STATE_SEP    '@'

String getCommand(String message);
String getParameters(String message);
int numberOfParameters(String parameters);
String getParameter(String parameters, int position);

#endif
