#include <SPI.h>
#include <LoRa.h>

#define BAND  915E6

uint32_t count = 0;

void setup() {
 Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Send");

  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  LoRa.beginPacket();
  LoRa.print("lora: ");
  LoRa.print(count);
  LoRa.endPacket();
  ++count;
  delay(1500);                       
}
