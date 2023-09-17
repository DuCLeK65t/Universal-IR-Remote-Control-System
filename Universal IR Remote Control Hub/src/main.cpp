#include "global_variables.h"

#include <Arduino.h>
#include "Communication.h"


/*Wi-Fi configuration*/
// SSID and Password
const char* ssid = "LEDUCANH";
const char* password = "0368080808";

// MQTT Broker IP address
const char* mqtt_server = "192.168.1.144";
/*End of Wi-Fi configuration*/

void setup() {
  Serial.begin(115200);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  // Maintain the connection / Continuously process MQTT messages
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    
    // Convert the value to a char array
    char tempString[8];
    dtostrf(temperature, 1, 2, tempString);
    Serial.print("Temperature: ");
    Serial.println(tempString);
    client.publish("esp32/temperature", tempString);
    
    // Convert the value to a char array
    char humString[8];
    dtostrf(humidity, 1, 2, humString);
    Serial.print("Humidity: ");
    Serial.println(humString);
    client.publish("esp32/humidity", humString);
  }
}