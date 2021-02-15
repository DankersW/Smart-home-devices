#include <Arduino.h>
#include "src/radio.h"
#include "src/sensor.h"

#define LED_BUILTIN 2

Radio *radio = new Radio();
Sensor *sensor = new Sensor();

Sensor::SensorData sensor_data = {};

void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); 
    
    radio->begin();

    blink_sequence();
}

void loop()
{
    digitalWrite(LED_BUILTIN, LOW);
    //radio->loop(); 

    sensor_data = sensor->read();
    Serial.println(sensor_data.temp);
    Serial.println(sensor_data.humi);
    Serial.println("");

    //radio->publish("iot/test", "hello world");
    delay(3000);
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
}