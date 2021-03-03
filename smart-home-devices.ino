#include <Arduino.h>
#include "src/types.h"
#include "src/radio.h"
#include "src/sensor.h"
#include "src/serializer.h"

#define LED_BUILTIN 2
#define TEN_MINUTES 600000

Sensor *sensor = new Sensor();
Radio *radio = new Radio();
Serializer *serializer = new Serializer();

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); 
    
    radio->begin();
    sensor->begin();

    blink_sequence();
}

void loop()
{    
    radio->loop(); 

    SensorData sensor_data = sensor->poll();
    
    std::string json_message = serializer->to_json(sensor_data);
    radio->publish("iot/devices/dev_001/telemetry", json_message.c_str());

    delay(TEN_MINUTES);
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
