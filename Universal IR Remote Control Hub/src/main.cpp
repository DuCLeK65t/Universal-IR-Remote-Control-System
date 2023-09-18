//   __  __     _                       _________  ___                 __      _____          __           ____ __     __ 
//  / / / /__  (_)  _____ _______ ___ _/ /  _/ _ \/ _ \___ __ _  ___  / /____ / ___/__  ___  / /________  / / // /_ __/ / 
// / /_/ / _ \/ / |/ / -_) __(_-</ _ `/ // // , _/ , _/ -_)  ' \/ _ \/ __/ -_) /__/ _ \/ _ \/ __/ __/ _ \/ / _  / // / _ \
// \____/_//_/_/|___/\__/_/ /___/\_,_/_/___/_/|_/_/|_|\__/_/_/_/\___/\__/\__/\___/\___/_//_/\__/_/  \___/_/_//_/\_,_/_.__/
//------------------------------------------------------------------------------------------------------------------------

#include "global_variables.h"

#include <Arduino.h>
#include "Communication.h"

/* Wi-Fi configuration ----------*/
// SSID and Password
const char* ssid = "LEDUCANH";
const char* password = "0368080808";

// MQTT Broker IP address
const char* mqtt_server = "3.73.193.253";
uint16_t port = 1883;
/*---------- End of Wi-Fi configuration ----------*/

void setup() {
  Serial.begin(115200);

  setup_wifi();
  client.setServer(mqtt_server, port);
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