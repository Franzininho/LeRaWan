#include <WiFi.h>
#include <esp_now.h>
#include <lerawan_comum.h>

#define buzzer 3
#define led 43
#define ledError 33

Info dados;

void recebeDados(const uint8_t *senderMac, const uint8_t *incomingData, int len);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  if (esp_now_init() != 0) {
    espNowFailed(ledError);
  }

  esp_now_register_recv_cb(recebeDados);
}

void loop() {
}

void recebeDados(const uint8_t *senderMac, const uint8_t *incomingData, int len) {
  memcpy(&dados, incomingData, sizeof(dados));
  Serial.print("botao: ");
  Serial.println(dados.button);
  // Serial.print("caiu: ");
  // Serial.println(dados.fall);

  digitalWrite(led, HIGH);
  tone(buzzer, 1245);
  delay(1500);
  digitalWrite(led, LOW);
  noTone(buzzer);
}