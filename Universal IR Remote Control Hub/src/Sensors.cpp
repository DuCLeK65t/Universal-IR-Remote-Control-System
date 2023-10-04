/* ------------------------------ */
#include "Sensors.h"
/* ------------------------------ */

/* DHT Sensor */
// DHT Sensor Initalization
DHT dht(dht_pin, dht_type);

// Sensor values
uint8_t humidity = 0;
uint8_t temperature = 0;

void readDHTsensor()
{
    // Read humidity
    humidity = dht.readHumidity();

    // Read temperature as Celsius (the default)
    temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature))
    {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }
}