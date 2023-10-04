/**
 *   @warning This file is using ArduinoJson version 6 (NOT version 5)
 *
 *   @see https: https://arduinojson.org/v6/doc/upgrade/
 *   to learn HOW TO UPGRADE program to ArduinoJson version 6
 */

#ifndef JSON_PROCESSING_H
#define JSON_PROCESSING_H

/* ------------------------------ */
#include <Arduino.h>
#include <ArduinoJson.h>

#include "global_variables.h"
#include "IRProcessing.h"
/* ------------------------------ */

/* ------------------------------ */
extern const char *data_deviceMAC;
extern const char *data_IRcommand;

// extern const char *dataReceive_buffer;
extern const char *dataTransmit_buffer;

String encodeJSON(uint8_t humidity, uint8_t temperature);
bool decodeJSON(const char *jsonString);

#endif