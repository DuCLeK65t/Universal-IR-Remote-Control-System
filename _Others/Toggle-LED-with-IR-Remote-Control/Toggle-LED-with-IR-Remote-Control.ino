#include <IRremote.h>

int RECV_PIN = 3; // IR LED pin
int ledPin = 10;

decode_results results;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver

  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {  // Check if is there any IR Signal
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0xB847FF00:  // CH +
        digitalWrite(ledPin, HIGH);
        break;
      case 0xB946FF00:  // CH -
        digitalWrite(ledPin, LOW);
        break;
    }

    IrReceiver.resume();  // Enable receiving of the next value
  }
}
