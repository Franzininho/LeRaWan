# Instruções de atualização da biblioteca

## 1. Endereços mac
O projeto pode ter até 3 microcontroladores envolvidos: um emissor, um repetidor e um receptor. 

Obtenha o endereço mac do emissor iniciando a sua conexão com Wifi e usando a função `printMac` definida na biblioteca, como no exemplo abaixo:

```
#include <WiFi.h>
#include <lerawan_comum.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
}

void loop() {
    printMac();
    delay(500);
}

```

O endereço que será impresso no Serial Monitor se parecerá com `50:02:91:A9:63:5C` e deve ser colocado na biblioteca no formato `{0x50, 0x02, 0x91, 0xA9, 0x63, 0x5C}` conforme os exemplos de endereços mac já disponíveis como exemplos na biblioteca.

## 2. Altere o WIFI_CHANNEL se achar necessário

O valor do WIFI_CHANNEL é 4, mas se você preferir pode utilizar outro canal que tenha menos tráfego no seu ambiente.

## 3. Adicione a biblioteca lerawan_comum na pasta de bibliotecas do Arduino da sua máquina. 

Em um sistema Linux, basta copiar a pasta lerawan_comum em `/Arduino/libraries` e em um sistema Windows, a pasta deve ser copiada para `Documents\Arduino\libraries` (ou caminho correspondente à pasta de bibliotecas do Arduino).