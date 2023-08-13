#include <WiFi.h>
#include <esp_now.h>
#include <comum.h>

#define buzzer 15

void recebeDados(const uint8_t *senderMac, const uint8_t *incomingData, int len);
Info dados;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  pinMode(buzzer, OUTPUT);
  if (esp_now_init() != 0) {
    espNowFailed(33);
  }
  esp_now_register_recv_cb(recebeDados);
  delay(400);
}

void loop() {
}

void recebeDados(const uint8_t *senderMac, const uint8_t *incomingData, int len) {
  memcpy(&dados, incomingData, sizeof(dados));
  Serial.print("botao: ");
  Serial.println(dados.button);
  Serial.print("caiu: ");
  Serial.println(dados.fall);

  tone(buzzer, 1245, 1500);
}

void printMac() {
  Serial.print("Mac: ");
  Serial.println(WiFi.macAddress());
}
