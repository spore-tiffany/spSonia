
#include "basic_config.h"
#include <ESP8266WiFi.h>
String  device_name ="room1";


const char* ssid = "TP-Link_0F26";
const char* password = "15722423";

const char* mqtt_server = "192.168.5.101";  // 例如 "192.168.1.100"
const int mqtt_port = 1883;
const char* mqtt_user = "spore";  // 若無則留空
const char* mqtt_password = "spore";  // 若無則留空


String clientID = "ESP01_"+device_name;
String subDeviceLCD = "/LCD";
String subDeviceUNO = "/"+device_name+"/UNO";
String subRoom1 = "/room1";
String subRoom2 = "/room2";
String subRoom3 = "/room3";
String subCentral = "/central";
String pubSyncCentral = "/central/sync";
String pubTopicDebug = "/central/Debug/"+device_name;
String pubTopicDHT = "/central/DHT/"+device_name;

bool bDebug = true;
bool remoteDebug = true;
bool serialDebug = false;
void seriallog(String str)
{
  if(bDebug == false)
  {
    return;
  } 
  else
  {
    if(remoteDebug == true)
    {
      pubMsg(pubTopicDebug,str);
    }
    
    if(serialDebug == true )
    {
      Serial.println(str);
    }
  }
}
void serialToUno(String data)
{
  Serial.println(data);
}
String getValue(String data, char separator, int index) {
  int found = 0;
  int start = 0;
  int end = -1;

  for (int i = 0; i <= data.length(); i++) {
    if (data.charAt(i) == separator || i == data.length()) {
      found++;
      if (found - 1 == index) {
        return data.substring(start, i);
      }
      start = i + 1;
    }
  }
  return "";
}

void serialReadfromUno()
{
  String input = Serial.readString();
  if(input != "")
  {
    String topic = getValue(input, ',', 0);
    String data = getValue(input, ',', 1); 
    pubMsg(topic,data); 
  }


}

void wifiSetup() {

  delay(50);
  seriallog("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    seriallog(".");
  }
  seriallog("\nWiFi connected, IP: " + WiFi.localIP().toString());
}
void setup() {
  Serial.begin(9600);
  wifiSetup();
  seriallog("setup:"+device_name);
  otaSetup();
  mqttSetup();
  
}


void loop()
{
  otaActive();
  mqttActive();
  dhtLoop();
  serialReadfromUno();

}
