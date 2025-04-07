#ifndef  _BASIC_CONFIG_H
#define  _BASIC_CONFIG_H

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>

LiquidCrystal_I2C lcd(0x27,16,2);
StaticJsonDocument<200> json_doc;


String  device_name ="UNOroom1";

void LEDHangle(int action);



#endif
