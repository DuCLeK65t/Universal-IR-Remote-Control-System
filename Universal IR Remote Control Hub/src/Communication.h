#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "global_variables.h"

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>


extern WiFiClient espClient;
extern PubSubClient client;
static long lastMsg = 0;
static char msg[50];
static int value = 0;

void setup_wifi();
void callback(char* topic, byte* message, unsigned int length);
void reconnect();

#endif