#include "basic_config.h"
int demoSenario =0;
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

  LEDsetup();
  LEDLoop();
  atomizerSetup();
  handleAtomizer(255);
  delay(5000);
  handleAtomizer(0);
 
}


void loop()
{
  swSerialloop();

  LEDLoop();
  
}
