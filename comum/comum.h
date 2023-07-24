uint8_t macReceptor[] = {0x34, 0xb4, 0x72, 0x6c, 0x60, 0xaa};
uint8_t macEmissor[] = {0xe8, 0xbd, 0x84, 0x93, 0x93, 0x02};

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
    digitalWrite(led, LOW);
    delay(100);
    }
    }

