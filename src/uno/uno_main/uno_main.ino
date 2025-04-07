#include "basic_config.h"
void redLEDSetup() {

  pinMode(LED_BUILTIN, OUTPUT);

  for(int i = 0 ; i < 3 ; i++ )
  {
    ledAlert(2);
  }
}

void ledAlert(int count)
{
  for(int i =  0 ; i < count*2 ; i++)
  {
    digitalWrite(LED_BUILTIN, i%2);
    delay(50);
  }
}
void setup()
{
  Serial.begin(9600);
  Serial.println("setup");
  redLEDSetup();
  swSerialSetup(); 
  lcdSetup();
  LEDsetup();
}


void loop()
{
  swSerialloop();
  lcdLoop();
  LEDLoop();
  
}
