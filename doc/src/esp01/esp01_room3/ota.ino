#include <ArduinoOTA.h>

void otaSetup() {


  ArduinoOTA.begin();
  seriallog("Arduino OTA Ready!");
  

}

void otaActive() {
  ArduinoOTA.handle();  // 處理 OTA 更新

}
