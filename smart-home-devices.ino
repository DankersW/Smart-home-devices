#include <Arduino.h>
#include "src/radio.h"

#define LED_BUILTIN 2



Radio *radio;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); 
    
    radio = new Radio();
    radio->begin();

    blink_sequence();
}

void loop()
{
    digitalWrite(LED_BUILTIN, LOW); 
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