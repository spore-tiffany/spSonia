//#include <SimpleDHT.h> 
#include <DHT.h>

int pinDHT11 = 2;
#define DHTTYPE DHT11 
DHT dht(pinDHT11, DHTTYPE);
unsigned long dhtTimer = 0;
unsigned long duration = 10000; 

void dhtSetup() {
  dht.begin();
  dhtTimer = millis();

}
String getDHTData()
{
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    //temperature = 24.5;
    //humidity = 58.3;
    // start working...
    seriallog("=================================");
   if (isnan(humidity) || isnan(temperature)) {
      seriallog("Failed to read from DHT sensor!");
      return "";
    }

    char buf[50];
    sprintf(buf,"{\"dht\":[\"%s\",%.1f,%.1f]}",device_name.c_str(),temperature,humidity);
    String strData(buf);
    seriallog(strData);

  

    return strData;
}

void dhtLoop() {

    if(dhtAutoUpload)
    {
      if(millis()-dhtTimer > duration)
      {

        String str = getDHTData();
        if(str !="")
        {
          //if(device_name == "room1")
          {
            serialToUno(str);
          }
          pubMsg(pubTopicDHT,str);
          if(device_name != "room1")
          {
              pubMsg(subDeviceLCD,str);
          }

        }
        dhtTimer = millis();
      }
    }
    //delay(3000);  //每3秒顯示一次
}
