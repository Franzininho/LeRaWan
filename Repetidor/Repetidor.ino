#include <WiFi.h>
#include <esp_now.h>
#include <comum.h>
#include <M5StickC.h>

esp_now_peer_info_t infoReceptor;

void repassaDados(const uint8_t *senderMac, const uint8_t *incomingData, int len);
Info dados;

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != 0) {
    espNowFailed(M5_LED);
  }
  esp_now_register_recv_cb(repassaDados);

  memcpy(infoReceptor.peer_addr, macReceptor, 6);
  esp_now_add_peer(&infoReceptor);
  delay(400);
}

void loop() {
}

void repassaDados(const uint8_t *senderMac, const uint8_t *incomingData, int len) {
  memcpy(&dados, incomingData, sizeof(dados));
  Serial.println("recebi");
   int resultado;
  do {
    dados.button = true;
    resultado = esp_now_send(macReceptor, (uint8_t *)&dados, sizeof(dados));
    delay(200);
  } while (resultado != 0);
  Serial.println("repassei");

}

void printMac() {
  Serial.print("Mac: ");
  Serial.println(WiFi.macAddress());
}


