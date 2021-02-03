#include <Arduino.h>

#include "src/radio.h"

#define LED_BUILTIN 2

Radio r = Radio();

void setup()
{
    // setup radio layer
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); 
}

void loop()
{
    digitalWrite(LED_BUILTIN, r.get_state()); 
}