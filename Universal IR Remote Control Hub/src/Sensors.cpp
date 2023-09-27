#include "Sensors.h"
/* ------------------------------ */

/* DHT Sensor */
DHT dht(dht_pin, dht_type);

//Sensor values
uint8_t temperature = 0;
uint8_t humidity = 0;

void readDHTsensor()
{
    // Read humidity
    humidity = dht.readHumidity();

    // Read temperature as Celsius (the default)
    temperature = dht.readTemperature();

    // Read temperature as Fahrenheit (isFahrenheit = true)
    // float temperature = dht.readTemperature(true);
}