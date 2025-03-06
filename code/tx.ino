#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 4   
#define CSN_PIN 5   
#define SCK_PIN 18  
#define MISO_PIN 19  
#define MOSI_PIN 23  
#define LED_PIN 2

RF24 radio(CE_PIN, CSN_PIN); // CE, CSN

void setup() {
  Serial.begin(9600);
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CSN_PIN); // SCK, MISO, MOSI, SS

  
  radio.begin(); // Khởi động module nRF24L01
  radio.openWritingPipe(0xF0F0F0F0E1LL);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  if (Serial.available()) {
    char text = Serial.read();
    Serial.print("Đang gửi: ");
    Serial.println(text);
    bool success = radio.write(&text, sizeof(text));
    if (success) {
      Serial.println("Gửi thành công!");
    } else {
      Serial.println("LỖI: Không thể gửi dữ liệu! Kiểm tra module.");
    }
    delay(50);
  }
}
