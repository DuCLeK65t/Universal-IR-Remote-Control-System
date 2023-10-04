/**  __  __     _                       _________  ___                 __      _____          __           ____ __     __
 *  / / / /__  (_)  _____ _______ ___ _/ /  _/ _ \/ _ \___ __ _  ___  / /____ / ___/__  ___  / /________  / / // /_ __/ /
 * / /_/ / _ \/ / |/ / -_) __(_-</ _ `/ // // , _/ , _/ -_)  ' \/ _ \/ __/ -_) /__/ _ \/ _ \/ __/ __/ _ \/ / _  / // / _ \
 * \____/_//_/_/|___/\__/_/ /___/\_,_/_/___/_/|_/_/|_|\__/_/_/_/\___/\__/\__/\___/\___/_//_/\__/_/  \___/_/_//_/\_,_/_.__/
 */

/**
 * Copyright (C) 2023 by Duc Le
 * llduc.312@gmail.com
 */

/**
 * @brief Assignment for the IoT and Application subject
 * by Duc Le, Nga Nguyen Phuong and Phuc Ngo Le Xuan
 *
 * @see https://github.com/DuCLeK65t/IoT-Universal-IR-Remote-Control-System
 */

/* ------------------------------ */
#include <Arduino.h>

#include "global_variables.h"
#include "Communication.h"
#include "JSONProcessing.h"
#include "IRProcessing.h"
#include "Sensors.h"
/* ------------------------------ */

/* ---------- Communication Configuration ---------- */

// SSID and Password
const char *ssid = "LEDUCANH";
const char *password = "0368080808";

// MQTT Broker IP address
// HiveMQ Public MQTT Broker: https://www.mqtt-dashboard.com/
const char *mqtt_server = "42.118.7.35";

// Default MQTT Port
const uint16_t port = 1883;

/* ---------- End of Communication Configuration ---------- */

void setup()
{
  Serial.begin(115200);

  // Wi-Fi
  setup_wifi();

  // MQTT
  client.setServer(mqtt_server, port);
  client.setCallback(callback);

  // Sensors
  dht.begin();

  // Actuators
  irsend.begin();
}

void loop()
{
  /* Check MQTT connection */
  if (!client.connected())
  {
    reconnect();
  }
  client.loop(); // Maintain the connection and Continuously process MQTT messages

  /* Read Humidity and Temperature sensor */
  readDHTsensor();

  /* Serialize messages */
  String dataTransmit_buffer = encodeJSON(humidity, temperature); //
  
  /* Published messages every 5 seconds */
  long now = millis();
  if (now - lastMsg > 2000)
  {
    lastMsg = now;

    Serial.print("publish data: ");
    Serial.println(dataTransmit_buffer);
    client.publish("esp32/input", dataTransmit_buffer.c_str());
  }
}