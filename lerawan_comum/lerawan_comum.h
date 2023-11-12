uint8_t macReceptor[] = {0x34, 0xb4, 0x72, 0x6c, 0x60, 0xaa};
uint8_t macEmissor[] = {0xe8, 0xbd, 0x84, 0x93, 0x93, 0x02};
uint8_t macExtensor[] = {0x50, 0x02, 0x91, 0xA9, 0x63, 0x5C};

#define WIFI_CHANNEL 4

struct __attribute__((packed))
Info {
  bool button;
  bool fall;
};


void espNowFailed(int led){
  pinMode(led,OUTPUT);
  while(true){
      digitalWrite(led, HIGH);
      delay(100);
      Serial.printf("ESP-NOW Failed");
      digitalWrite(led, LOW);
      delay(100);
    }
}

void printMac() {
  Serial.printf("Mac: %s \n", WiFi.macAddress().c_str());
}


