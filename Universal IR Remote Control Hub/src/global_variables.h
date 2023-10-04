/**
 * @file global_variables.h
 * @brief Global variables initialization
 * @warning ADC2 pins cannot be used when Wi-Fi is used, so use an ADC1 GPIO instead
 */

#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

/* ------------------------------ */
#include <Arduino.h>
#include <WiFi.h>
/* ------------------------------ */

/* ---------- MAC Address ---------- */

static String thisDevice_MAC = WiFi.macAddress();

/* ---------- End of MAC Address ---------- */

/* ---------- Communication Configuration ---------- */

// SSID/Password
extern const char *ssid;
extern const char *password;

// MQTT Broker IP address
extern const char *mqtt_server;

// MQTT Port
extern const uint16_t port;

/* ---------- End of Communication Configuration ---------- */

/* ---------- Sensors Configuration ---------- */

// Uncomment using sensor type!
// #define dht_type DHT22 // DHT 22
#define dht_type DHT11 // DHT 11

// Digital pin connected to the DHT sensor
const uint8_t dht_pin = 32;

/* ---------- End of Sensors Configuration ---------- */

/* ---------- Actuators Configuration ---------- */

// Test LED Pin
// const uint8_t testLed_pin = 2;

// IR LED Pin
const uint8_t irLed_pin = 22;

/* ---------- End of Actuators Configuration ---------- */

#endif