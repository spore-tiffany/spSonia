#include <SoftwareSerial.h>
int BTN_NONE = 0;
int BTN_PRESS = 1;
int BTN_RELEASE = 2;
int BTN_SHORT = 3;
int BTN_LONG = 4;
bool serialDebug = false;
#define rxPin 3
#define txPin 2

SoftwareSerial mySerial(rxPin, txPin);

void swSerialSetup()  {

    mySerial.begin(9600);
    

}
String swSwrialReadCommand()
{
  String s="";
  while(mySerial.available())
  {
    char c = mySerial.read();
    if(c!='\n')
    {
      
      s+=c;
    }
    delay(5);

  }
  return s;

}
void swSerialloop() {
  String s = swSwrialReadCommand();
  if(s!="")
  {
    String str = "get data: "+s;

    Serial.println(str);
    ledAlert(5);
    if(serialDebug==false)
      parseJson(s);
  }
  delay(50);
}
void handleBtn(int btnPress)
{
  if(btnPress == BTN_SHORT)
  {
    demoSenario++;
    demoSenario%=3;
    switch(demoSenario)
    {
    case 0:
      ledState = 0;
      LEDHangle(ledState);
    break;
    case 1:
      ledState =1 ;
      LEDHangle(ledState);
      break;
    case 2:
      ledState =2 ;
      LEDHangle(ledState);
      break;
    default:
    break;
    }
  }
  else if(btnPress == BTN_LONG)
  {
    if(ledState == 0)
    {
      ledState = 1;
    }
    else
    {
      ledState = 0;
    }
    LEDHangle(ledState);
    handleRelay(ledState);

  }
}


void parseJson(String data)
{
  //data = "{\"dht\":[\"room1\",11.3,166.8]}";

  DeserializationError error = deserializeJson(json_doc, data);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());

    return;
  }
  else if(json_doc.containsKey("LED"))
  {
    //
    int ledAct = json_doc["LED"][0];
    LEDHangle(ledAct);
  }
  else if(json_doc.containsKey("btn"))
  {
    int btnAct = json_doc["btn"];
    handleBtn(btnAct);
  }
  
}

