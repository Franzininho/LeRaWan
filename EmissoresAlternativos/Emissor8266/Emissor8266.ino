#include <ESP8266WiFi.h>
#include <espnow.h>
#include <lerawan_comum.h>

Info dados;

void setup() {

  Serial.begin(115200);
  pinMode(BUILTIN_LED,OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != 0) {
    espNowFailed(BUILTIN_LED);
  }

  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_add_peer(macReceptor, ESP_NOW_ROLE_SLAVE, WIFI_CHANNEL, NULL, 0);
  esp_now_add_peer(macExtensor, ESP_NOW_ROLE_SLAVE, WIFI_CHANNEL, NULL, 0);

  sendData();
  ESP.deepSleep(0);
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
