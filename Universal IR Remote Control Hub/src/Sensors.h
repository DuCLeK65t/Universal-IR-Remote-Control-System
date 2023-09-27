#ifndef SENSORS_H
#define SENSORS_H

#include "global_variables.h"

#include <Arduino.h>
#include <DHT.h>
/* ------------------------------ */

extern DHT dht;

// Sensor values
extern uint8_t temperature;
extern uint8_t humidity;

void readDHTsensor();

#endif