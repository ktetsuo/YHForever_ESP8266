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
#include "FS.h"
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
  if (!SPIFFS.begin()) {
    Serial.println("SPIFFS.begin fail");
  }
}

void loop() {
}

boolean onButton() {
  ESP8266WebServer* server = Nefry.getWebServer();
  String id = server->arg("id");
  String val = server->arg("val");
  Serial.println("id:" + id + ", val:" + val);
  if (val == "1") { // Send
    File fd = SPIFFS.open("/" + id + ".bin", "r");
    if (fd) {
      unsigned long data;
      size_t bytes = fd.read((unsigned char*)&data, sizeof(data));
      if (bytes == sizeof(data)) {
        Serial.print("load: ");
        Serial.println(data);
        // この辺で赤外線送信する
      } else {
        Serial.println("file read error.");
      }
      fd.close();
    } else {
      Serial.println("Not yet learned.");
    }
  }
  if (val == "2") { // Learn
    File fd = SPIFFS.open("/" + id + ".bin", "w");
    if (fd) {
      unsigned long data = millis();  // 暫定で現在のミリ秒を記憶する
      // この辺で赤外線受信する
      size_t bytes = fd.write((unsigned char*)&data, sizeof(data));
      if (bytes == sizeof(data)) {
        Serial.print("save: ");
        Serial.println(data);
      } else {
        Serial.println("file write error.");
      }
      fd.close();
    } else {
      Serial.println("file open(w) error.");
    }
  }
  return true;
}

