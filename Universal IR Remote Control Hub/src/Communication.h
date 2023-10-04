#ifndef COMMUNICATION_H
#define COMMUNICATION_H

/* ------------------------------ */
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

#include "global_variables.h"
/* ------------------------------ */

/* ------------------------------ */
extern WiFiClient espClient;
extern PubSubClient client;
static long lastMsg = 0;

void setup_wifi();
void callback(char *topic, byte *message, unsigned int length);
void reconnect();

#endif