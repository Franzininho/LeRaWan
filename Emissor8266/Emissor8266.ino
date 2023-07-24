#include <ESP8266WiFi.h>
#include <espnow.h>
#include <comum.h>

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

  digitalWrite(BUILTIN_LED,HIGH);
  sendData();
  delay(200);
  digitalWrite(BUILTIN_LED,LOW);
  ESP.deepSleep(0);
}

void loop() {
}


void sendData() {
  int resultado;  //esp_error_t
  do {
    dados.button = true;
    resultado = esp_now_send(NULL, (uint8_t *)&dados, sizeof(dados));
    delay(200);
  } while (resultado != 0);  //ESP_OK
  dados.button = false;
}

void printMac() {
  Serial.printf("Mac: %s, ", WiFi.macAddress().c_str());
}
