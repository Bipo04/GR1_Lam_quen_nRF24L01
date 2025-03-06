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
char msg;

void setup() {
  Serial.begin(9600);
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CSN_PIN); // SCK, MISO, MOSI, SS

  // Khởi tạo module nRF24L01
  radio.begin();
  radio.openReadingPipe(0, 0xF0F0F0F0E1LL); // Mở kênh nhận
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening(); // Đặt chế độ nhận dữ liệu

  pinMode(LED_PIN, OUTPUT);
}
 
void loop(){
  if (radio.available()){
    while (radio.available()){
      radio.read(&msg, sizeof(msg));
      if(msg == '1') {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("LED ON");
      } else if(msg == '0') {
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED OFF");
      }
    }
    delay(50);
  }
}