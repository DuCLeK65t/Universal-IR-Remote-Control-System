/* ------------------------------ */
#include "JSONProcessing.h"
/* ------------------------------ */

/* ---------- Decode message variables Initialization ---------- */

const char *data_deviceMAC;
const char *data_IRcommand;

/* ---------- End of Decode message variables Initialization ---------- */

String encodeJSON(uint8_t humidity, uint8_t temperature)
{
    const size_t capacity = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3);
    StaticJsonDocument<255> data_encode;

    JsonObject data = data_encode.createNestedObject("data");
    data["device_id"] = thisDevice_MAC;
    data["humidity"] = humidity;
    data["temperature"] = temperature;

    String jsonString = "";
    serializeJson(data_encode, jsonString);

    data_encode.clear();

    return jsonString;
}

bool decodeJSON(const char *jsonString)
{
    StaticJsonDocument<255> data_decode; // Store JSON data
    DeserializationError error = deserializeJson(data_decode, jsonString);

    if (error)
    {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());

        return false;
    }
    else
    {
        data_deviceMAC = data_decode["data"]["deviceID"]; // eg: "40:22:D8:EA:06:F8"
        data_IRcommand = data_decode["data"]["command"]; // eg: "0xFFE21D" "0xFF629D"
    }

    data_decode.clear();

    return true;
}