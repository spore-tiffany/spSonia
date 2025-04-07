

#include <PubSubClient.h>



WiFiClient espClient;
PubSubClient client(espClient);


// 當 MQTT 訂閱主題收到訊息時的回調函式
void callback(char* topic, byte* payload, unsigned int length) {
  String strTopic = String(topic);
  String msg = "Message arrived ["+strTopic+"] ";

  String data = "";
  for (int i = 0; i < length; i++) {
    data+=(char)payload[i];
  }
  //Serial.println(data);
    seriallog(msg);
    seriallog(data);
  serialToUno(data);
  //String s = subCentral+","+subDeviceESP+","+subDeviceUNO+","+subRoom1+","+subRoom2+","+subRoom3+",";
  //seriallog(s);
  if(strTopic==subCentral)
  {
    seriallog(strTopic);
    handleCentral(data); 
  }
  else if(strTopic==subDeviceLCD)
  {
    seriallog(strTopic);

  }
  else if(strTopic==subDeviceUNO)
  {
    seriallog(strTopic);
    serialToUno(data);
  }
  else if(strTopic == subRoom1)
  {
    seriallog(strTopic);
    serialToUno(data);
  }
  /*
  else if(strTopic == subRoom2 )
  {
    seriallog(strTopic);
    serialToUno(data);
  }
  else if(strTopic == subRoom3 )
  {
    seriallog(strTopic);
    serialToUno(data);
    
  }
  */
}

void handleCentral(String cmd) {
/*
  if("switch")
  {
    gCentral=(gCentral+1)%2;
    setCentral(gCentral);

  }
  */
}
void setCentral(bool state)
{
  /*
    if(gCentral == CENTRAL_DISABLE)
      handleLED("LED_OFF");
    else if(gCentral == CENTRAL_ENABLE)
      handleLED("LED_ON");
      */
}

void handleLED(String cmd) {
  /*
  if(cmd == "LED_ON")
  {
    enable_led = true;
  }
  else if(cmd == "LED_OFF")
  {
    enable_led = false;
    FastLED.clearData();
    FastLED.show();
  }
  else if(cmd=="switch")
  {
    enable_led = (enable_led+1)%2;
    if(enable_led == false)
    {
      FastLED.clearData();
      FastLED.show();
    }
  }
  */
}

// 連接 MQTT 伺服器
void reconnect() {
  while (!client.connected()) {
    seriallog("Attempting MQTT connection...");

    if (client.connect(clientID.c_str(), mqtt_user, mqtt_password)) {
      seriallog(" connected!");
      if(device_name == "room1")
      {
        client.subscribe(subDeviceLCD.c_str());  // 訂閱LCD測試主題
      }
      client.subscribe(subDeviceUNO.c_str()); 
      client.subscribe(subCentral.c_str()); 
      
      client.subscribe(subRoom1.c_str()); 
      /*
      client.subscribe(subRoom2.c_str()); 
      client.subscribe(subRoom3.c_str());
      */
      if(device_name == "room1")
      {

      }

    } else {
      seriallog(" failed, rc=");
      seriallog(String(client.state()));
      seriallog(" retrying in 5 seconds...");
      delay(5000);
    }
  }
  client.publish(pubSyncCentral.c_str(),device_name.c_str());
}

void mqttSetup() {
  //Serial.begin(115200);
  //setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void mqttActive() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
/*
  // 發送 MQTT 訊息
  static unsigned long lastMsg = 0;
  if (millis() - lastMsg > 5000) {
    lastMsg = millis();
    String msg = "Hello from ESP8266!";
    client.publish("esp/test", msg.c_str());
    Serial.println("Sent: " + msg);
  }
  */
}

void pubMsg(String pubTopic,String s)
{
   if(serialDebug == true)
   {
    /*
     Serial.print("topic name, data: ");
     Serial.println(pubTopic);
     Serial.print(" , ");
     
     Serial.println(s);
     */
   }
   
   if(client.connected())
   {
     client.publish(pubTopic.c_str(), s.c_str());
   }
}
