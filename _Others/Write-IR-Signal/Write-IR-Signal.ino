#include <IRremote.h>

IRsend irsend(3);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Gửi tín hiệu hồng ngoại
  unsigned long irCode = 0xFFE21D;
  irsend.sendNEC(irCode, 32);
  delay(1000);
}