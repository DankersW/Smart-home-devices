#include <Arduino.h>

#include "src/radio/radio.h"

#define LED_BUILTIN 2


Radio radio;

void setup()
{
    // setup radio layer
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); 
    radio = Radio();
}

void loop()
{
    digitalWrite(LED_BUILTIN, radio.get_state()); 
}