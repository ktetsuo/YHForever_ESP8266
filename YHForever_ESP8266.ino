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

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRsend.h>
#include <IRutils.h>

// 受光モジュール
#define RECV_PIN   5 // 赤外線受光モジュール
#define IR_LED     2 // 送信用赤外線LED
#define POWER_LED 12 // 電源LED

// 赤外線受信設定
#define CAPTURE_BUFFER_SIZE 1024
#define TIMEOUT  50U
#define MIN_UNKNOWN_SIZE 12

IRrecv irrecv(RECV_PIN, CAPTURE_BUFFER_SIZE, TIMEOUT, true);
decode_results results;
IRsend irsend(IR_LED);

int recieving_channel = 0;  // 受信中チャンネル（0は未受信）

void setup() {
  // プログラム名登録
  Nefry.setProgramName("YHRemocon");
  // 電源LED（緑）をつける
  pinMode(POWER_LED, OUTPUT);
  digitalWrite(POWER_LED, HIGH);
  // HTMLリンクの動作の設定
  Nefry.getWebServer()->on("/remocon.html",  [&]() {
    Nefry.getWebServer()->send(200, "text/html", REMOCON_HTML);
  });
  Nefry.setIndexLink("Remocon", "/remocon.html"); // トップページへリンクを作成
  Nefry.getWebServer()->on("/button",  [&]() {
    Nefry.getWebServer()->send(200, "text/html", onButton() ? "Success" : "Failed");
  });
  // シリアル通信開始
  Serial.begin(115200);
  // ファイルシステムの初期化
  if (!SPIFFS.begin()) {
    Serial.println("SPIFFS.begin fail");
  }
  // 赤外線送受信の初期設定
  irrecv.setUnknownThreshold(MIN_UNKNOWN_SIZE);
  irrecv.enableIRIn();
  irsend.begin();
}

void loop() {
  // 受信中のときだけ実行
  if (0 < recieving_channel) {
    // 受信したら実行
    if (irrecv.decode(&results)) {
      // 受信したコードの格納とシリアル表示
      int len = results.rawlen - 1;
      uint16_t code[len];
      Serial.println("Recieved " + String(len) + "bytes:");
      for (int i = 0; i < len; i++) {
        code[i] = results.rawbuf[i + 1] * RAWTICK;
        Serial.print(code[i]);
        Serial.print(", ");
      }
      Serial.println("");
      // ファイルに保存
      saveCode(recieving_channel, code, len * sizeof(*code));
      // 受信中チャンネルをクリア
      recieving_channel = 0;
    }
  }
}

boolean onButton() {
  // /button?id=##&val=## にアクセスされたときに呼ばれる
  ESP8266WebServer* server = Nefry.getWebServer();
  int id = server->arg("id").toInt();
  int val = server->arg("val").toInt();
  Serial.println("id:" + String(id) + ", val:" + String(val));
  switch (val) {
    case 1: // Send
      return onSend(id);
    case 2: // Learn
      return onLearn(id);
    default:
      break;
  }
  return true;
}

boolean onSend(int id)
{
  // ファイルから読み込み
  uint16_t code[256];
  int bytes = loadCode(id, code, sizeof(code));
  int len = bytes / sizeof(*code);
  // 読み込めたら表示と赤外線送信
  if (0 < len) {
    Serial.println("Send " + String(len) + "bytes:");
    for (int i = 0; i < len; i++) {
      Serial.print(code[i]);
      Serial.print(", ");
    }
    Serial.println("");
    irsend.sendRaw(code, bytes / sizeof(uint16_t), 38);
  }
  return true;
}

boolean onLearn(int id)
{
  // 受信開始前に、これまでに受信していたデータを読み捨て
  irrecv.decode(&results);
  // 受信を開始
  recieving_channel = id;
  Serial.println("start recieve: " + String(id));
  return true;
}

int saveCode(int id, const uint16_t* code, size_t codesize)
{
  // ファイルに保存
  String filename = "/" + String(id) + ".bin";
  Serial.println(filename);
  File fd = SPIFFS.open(filename, "w");
  if (!fd) {
    Serial.println("file open(w) error.");
    return -1;
  }
  size_t bytes = fd.write((const uint8_t*)code, codesize);
  Serial.println("save: " + String(bytes) + "bytes");
  fd.close();
  return bytes;
}

int loadCode(int id, uint16_t* code, size_t codesize)
{
  // ファイルから読み込み
  String filename = "/" + String(id) + ".bin";
  Serial.println(filename);
  File fd = SPIFFS.open(filename, "r");
  if (!fd) {
    Serial.println("file open(r) error.");
    return -1;
  }
  size_t bytes = fd.read((unsigned char*)code, codesize);
  Serial.println("load: " + String(bytes) + "bytes");
  fd.close();
  return bytes;
}

