#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H    

#include <Arduino.h>

/* Wi-Fi configuration ---------- */
// SSID/Password
extern const char* ssid;
extern const char* password;

// MQTT Broker IP address
extern const char* mqtt_server;

// MQTT Port
extern uint16_t port;
/* ---------- End of Wi-Fi configuration ---------- */


/* Sensors ---------- */
static float temperature = 0;
static float humidity = 0;
/* ---------- End of Sensors ---------- */


/* Actuators configuration ---------- */
// int actuatorPin = x;
/* ---------- End of Actuators configuration ---------- */

// LED Pin
const int ledPin = 2;

#endif