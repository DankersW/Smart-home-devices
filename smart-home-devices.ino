#include <Arduino.h>
#include "src/types.h"
#include "src/radio.h"
#include "src/sensor.h"
//#include "src/serializer.h"

#define LED_BUILTIN 2

Sensor sensor = Sensor();
Radio radio = Radio();

Serializer serializer = Serializer();

SensorData sensor_data = {};


void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); 
    
    radio.begin();

    blink_sequence();
}

void loop()
{
    delay(2000);
    radio.loop(); 
    sensor_data = sensor.poll();

    Serial.println(sensor_data.humi);
    Serial.println(sensor_data.temp);
    
    //std::string json_message = serializer->to_json(sensor_data);
    //Serial.println(json_message.c_str());
    //radio->publish("iot/devices/test_device_001/telemetry", json_message.c_str());

    
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
