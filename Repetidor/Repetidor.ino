#include <WiFi.h>
#include <esp_now.h>
#include <lerawan_comum.h>

#define ledError 33

void repassaDados(const uint8_t *senderMac, const uint8_t *incomingData, int len);

esp_now_peer_info_t infoReceptor;
Info dados;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    espNowFailed(ledError);
  }

  esp_now_register_recv_cb(repassaDados);

  memcpy(infoReceptor.peer_addr, macReceptor, 6);
  esp_now_add_peer(&infoReceptor);
}

void loop() {
}

void repassaDados(const uint8_t *senderMac, const uint8_t *incomingData, int len) {
  memcpy(&dados, incomingData, sizeof(dados));
   int resultado;
  do {
    dados.button = true;
    resultado = esp_now_send(macReceptor, (uint8_t *)&dados, sizeof(dados));
    delay(200);
  } while (resultado != 0);
}

