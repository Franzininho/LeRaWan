#include <WiFi.h>
#include <esp_now.h>
#include <lerawan_comum.h>

#define btn 4
#define ledError 7

Info dados;

esp_now_peer_info_t infoReceptor;
// esp_now_peer_info_t infoRepetidor;  // descomentar se usar repetidor

void setup() {
  Serial.begin(115200);
  pinMode(btn, INPUT);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != 0) {
    espNowFailed(ledError);
  }

  memcpy(infoReceptor.peer_addr, macReceptor, 6);
  // memcpy(infoRepetidor.peer_addr, macRepetidor, 6);  // descomentar se usar repetidor

  esp_now_add_peer(&infoReceptor);
  // esp_now_add_peer(&infoRepetidor);  // descomentar se usar repetidor

  sendData();
  esp_deep_sleep_enable_gpio_wakeup(1 << btn, ESP_GPIO_WAKEUP_GPIO_HIGH);
  esp_deep_sleep_start();
}

void loop() {
}

void sendData() {
  int resultado;
  do {
    dados.button = true;
    resultado = esp_now_send(NULL, (uint8_t *)&dados, sizeof(dados));
    delay(200);
  } while (resultado != 0);
  dados.button = false;
}
