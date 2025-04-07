#ifndef  _BASIC_CONFIG_H
#define  _BASIC_CONFIG_H


#include <ArduinoJson.h>
#define relayPin 7
int ledState = 2;
StaticJsonDocument<200> json_doc;


String  device_name ="UNOroom3";

void LEDHangle(int action);



#endif
