void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    String text = Serial.readString();
    Serial.println(text);
  }
  delay(50);
}
