#include <WiFi.h>
#include <esp_now.h>
#include <comum.h>
#include <M5StickC.h>

#define btn GPIO_NUM_37

Info dados;

esp_now_peer_info_t infoReceptor;


void setup() {
  M5.begin();
  Serial.begin(9600);
  pinMode(M5_LED, OUTPUT);
  pinMode(btn, INPUT);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != 0) {
    espNowFailed(M5_LED);
  }

  memcpy(infoReceptor.peer_addr, macReceptor, 6);

  esp_now_add_peer(&infoReceptor);

  digitalWrite(M5_LED, HIGH);
  sendData();
  delay(200);
  digitalWrite(M5_LED, LOW);
  esp_sleep_enable_ext0_wakeup(btn, 1);
  M5.Axp.DeepSleep();
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

void printMac() {
  Serial.printf("Mac: %s, ", WiFi.macAddress().c_str());
}
