/*
    __  __     _                       _________  ___                 __      _____          __           ____ __     __
   / / / /__  (_)  _____ _______ ___ _/ /  _/ _ \/ _ \___ __ _  ___  / /____ / ___/__  ___  / /________  / / // /_ __/ /
  / /_/ / _ \/ / |/ / -_) __(_-</ _ `/ // // , _/ , _/ -_)  ' \/ _ \/ __/ -_) /__/ _ \/ _ \/ __/ __/ _ \/ / _  / // / _ \
  \____/_//_/_/|___/\__/_/ /___/\_,_/_/___/_/|_/_/|_|\__/_/_/_/\___/\__/\__/\___/\___/_//_/\__/_/  \___/_/_//_/\_,_/_.__/

  Assignment for the IoT and Application subject
  by Duc Le, Nga Nguyen Phuong and Phuc Ngo Le Xuan
  https://github.com/DuCLeK65t/IoT-Universal-IR-Remote-Control-System

  -----------------------------------------------------------------------------------------------------------------------
*/

#include "global_variables.h"

#include <Arduino.h>
#include "Communication.h"
#include "JSONProcessing.h"
#include "Sensors.h"

/* ---------- Wi-Fi Configuration ---------- */

// SSID and Password
const char *ssid = "LEDUCANH";
const char *password = "0368080808";

// MQTT Broker IP address
// HiveMQ Public MQTT Broker: https://www.mqtt-dashboard.com/
const char *mqtt_server = "3.121.97.109";

// Default MQTT Port
const uint16_t port = 1883;

/* ---------- End of Wi-Fi Configuration ---------- */

void setup()
{
  Serial.begin(115200);

  setup_wifi();
  client.setServer(mqtt_server, port);
  client.setCallback(callback);

  dht.begin();
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  // Maintain the connection / Continuously process MQTT messages
  client.loop();

  // Read Humidity and Temperature
  readDHTsensor();
  if (isnan(humidity) || isnan(temperature))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  /* Data Processing */
  const size_t capacity = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3);
  DynamicJsonDocument jsonBuffer(capacity);

  jsonBuffer["datatype"] = "publish";

  JsonObject data = jsonBuffer.createNestedObject("data");
  data["location_id"] = 2002;
  data["humidity"] = humidity;
  data["temperature"] = temperature;

  String data_str = "";
  serializeJson(jsonBuffer, data_str);

  const char *charPtr = data_str.c_str();

  /* End of Data Processing */

  long now = millis();
  if (now - lastMsg > 5000)
  {
    lastMsg = now;

    // Convert the value to a char array
    // char tempString[8];
    // dtostrf(temperature, 1, 2, tempString);
    Serial.print("data: ");
    Serial.println(charPtr);
    client.publish("esp32/datasend", charPtr);

    // // Convert the value to a char array
    // char humString[8];
    // dtostrf(humidity, 1, 2, humString);
    // Serial.print("Humidity: ");
    // Serial.println(humString);
    // client.publish("esp32/humidity", humString);
  }
}