
#include "basic_config.h"
#include <ESP8266WiFi.h>
String  device_name ="room3";


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
bool bRemote_Debug = true;
bool serialDebug = false;
void seriallog(String str)
{
  if(bDebug == false)
  {
    return;
  } 
  else
  {
    
    if(bRemote_Debug == true)
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

}
