// ボード: Nefry Modules -> ESP8266 Generic Modules
// Flash Mode: QIO
// Flash Size: 4M(3M SPIFFS)
// Debug port: Serial
// Debug Level: なし
// reset method: nodemcu
// Flash Frequency: 40MHz
// CPU Frequency: 80MHz
// Upload Speed: 234000

// 使用可能ピン 2,5,12,13,14,15,A0

#include <Nefry.h>
#include "remocon.h"

void setup() {
  Nefry.setProgramName("YHRemocon");//プログラム名登録
  Nefry.getWebServer()->on("/remocon.html",  [&]() {
    Nefry.getWebServer()->send(200, "text/html", REMOCON_HTML);
  });
  Nefry.setIndexLink("Remocon", "/remocon.html");
  Nefry.getWebServer()->on("/button",  [&]() {
    Nefry.getWebServer()->send(200, "text/html", onButton() ? "Success" : "Failed");
  });
  Serial.begin(115200);
}

void loop() {
}

boolean onButton() {
  ESP8266WebServer* server = Nefry.getWebServer();
  String id = server->arg("id");
  String val = server->arg("val");
  Serial.println("id:" + id + ", val:" + val);
  return true;
}

