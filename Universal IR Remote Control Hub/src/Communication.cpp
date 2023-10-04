/* ------------------------------ */
#include <WiFi.h>
#include <string.h>

#include "Communication.h"
#include "JSONProcessing.h"
#include "IRProcessing.h"
/* ------------------------------ */

/* MQTT Client Initialization */
WiFiClient espClient;
PubSubClient client(espClient);

/* Arrived Message */
// const char *dataReceive_buffer;

void setup_wifi()
{
    delay(10);
    // Connecting to a Wi-Fi network
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void callback(char *topic, byte *message, unsigned int length)
{
    Serial.print("Message arrived on topic: ");
    Serial.print(topic);
    Serial.println(". Message: ");
    String dataReceive_buffer;

    for (int i = 0; i < length; i++)
    {
        Serial.print((char)message[i]);
        dataReceive_buffer += (char)message[i];
    }
    Serial.println();

    // Control device according to the message
    if (String(topic) == "esp32/output")
    {
        if (!decodeJSON(dataReceive_buffer.c_str()))
        {
            return;
        }
        else
        {
            // Check MAC Address
            if (thisDevice_MAC.compareTo((String)data_deviceMAC))
            {
                uint64_t necData = strtoull(data_IRcommand, nullptr, 16);
                irsend.sendNEC(necData);
            }
            else
            {
                Serial.println("MAC address is not correct!");
            }
        }
    }
    else
    {
        Serial.println("Topic is not correct!");
    }
}

void reconnect()
{
    // Loop until we're reconnected
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        // Attempt to connect
        if (client.connect("ESP32Client"))
        {
            Serial.println("Connected to MQTT broker");
            // Subscribe
            client.subscribe("esp32/output");
        }
        else
        {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            Serial.println(" Try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}