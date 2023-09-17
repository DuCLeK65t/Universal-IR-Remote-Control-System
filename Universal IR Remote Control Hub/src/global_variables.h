#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H    

#include <Arduino.h>

/* Wi-Fi configuration */

// SSID/Password
extern const char* ssid;
extern const char* password;

// MQTT Broker IP address
extern const char* mqtt_server;

/* End of Wi-Fi configuration ---------- */


/* Sensors */

float temperature = 0;
float humidity = 0;

/* End of Sensors ---------- */


/* Actuators configuration  */

float temperature = 0;
float humidity = 0;

/* End of Actuators configuration ---------- */

// LED Pin
const int ledPin = 2;

#endif