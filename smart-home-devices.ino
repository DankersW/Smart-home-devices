#include <Arduino.h>
#include "src/types.h"
#include "src/radio.h"
#include "src/sensor.h"
#include "src/serializer.h"

#define LED_BUILTIN 2

Sensor *sensor = new Sensor();
Radio *radio = new Radio();
Serializer *serializer = new Serializer();

unsigned long time_previous_run = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); 
    
    radio->begin();
    sensor->begin();

    blink_sequence();
    digitalWrite(LED_BUILTIN, HIGH); // active low
}

void loop()
{    
    radio->loop(); 

    if (millis() - time_previous_run >= 600000)
    {
        time_previous_run = millis();
        update_sensor_data();
    }
}

void update_sensor_data()
{
    SensorData sensor_data = sensor->poll();
    std::string json_message = serializer->to_json(sensor_data);
    radio->publish("iot/devices/dev_001/telemetry", json_message.c_str());
}

void blink_sequence()
{
    for (int i=0; i<=5; i++)
    {
        digitalWrite(LED_BUILTIN, LOW); 
        delay(200);
        digitalWrite(LED_BUILTIN, HIGH); 
        delay(200);
    }
    digitalWrite(LED_BUILTIN, LOW);
}
