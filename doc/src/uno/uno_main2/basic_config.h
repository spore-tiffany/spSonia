#ifndef  _BASIC_CONFIG_H
#define  _BASIC_CONFIG_H


#include <ArduinoJson.h>
#define atomizerPin  6
int ledState = 2;
StaticJsonDocument<200> json_doc;


String  device_name ="UNOroom2";

void LEDHangle(int action);



#endif
