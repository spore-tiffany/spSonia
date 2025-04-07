#include <SoftwareSerial.h>

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


void parseJson(String data)
{
  //data = "{\"dht\":[\"room1\",11.3,166.8]}";

  DeserializationError error = deserializeJson(json_doc, data);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Error:");
    lcd.setCursor(0,1);
    lcd.print("json deserialize failed");
    lcdAlert(5,100);
    return;
  }
  lcd.clear();
  lcdAlert(2,200);
  if(json_doc.containsKey("dht"))
  {
    handleDHT();
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
    handleBtnCmd(btnAct);
  }
  
}
void handleDHT()
{


    String room =  json_doc["dht"][0];

    float t = json_doc["dht"][1];
    float h = json_doc["dht"][2];

    char buf[10];
    dtostrf(t,4,1,buf);
    lcd.setCursor(0,0);
    lcd.print(room+":");
    lcd.setCursor(0,1);
    lcd.print("T:");
    lcd.print(buf);
    lcd.print("c  ");
    
    dtostrf(h,4,1,buf);
//    lcd.setCursor(0,1);
    lcd.print("H:");
    lcd.print(buf);
    lcd.print("%");
    


}

void sendCmd(String topic,String cmd,int data)
{
  
  char buf[50];
  sprintf(buf,"{\"%s\":%d}",cmd.c_str(),data);

  String strData(buf);
  strData=topic+","+strData;
  Serial.println(strData);
  mySerial.print(strData);

}

