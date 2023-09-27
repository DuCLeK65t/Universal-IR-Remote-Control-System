#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include <Arduino.h>
/* ------------------------------ */

/* ---------- Wi-Fi Configuration ---------- */

// SSID/Password
extern const char *ssid;
extern const char *password;

// MQTT Broker IP address
extern const char *mqtt_server;

// MQTT Port
extern const uint16_t port;

/* ---------- End of Wi-Fi Configuration ---------- */

/* ---------- Sensors Configuration ---------- */

// Uncomment using sensor type!
#define dht_type DHT11 // DHT 11
// #define dht_type DHT22 // DHT 22

// Digital pin connected to the DHT sensor
const uint8_t dht_pin = 32;

/* ---------- End of Sensors Configuration ---------- */

/* ---------- Actuators Configuration ---------- */

// int actuatorPin = x;

// LED Pin
const int ledPin = 2;

/* ---------- End of Actuators Configuration ---------- */

#endif