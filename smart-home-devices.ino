#include <Arduino.h>
#include <ESP8266WiFi.h>


#define LED_BUILTIN 2


class Radio
{
    private:
        struct credentials
        {
            const char* ssid = "SaveOurWinters";
            const char* pwd =  "prettyflyforawifi";
        } _wifi_cred;

        bool _connect_to_network();

    public:
        Radio();
        ~Radio(){}
};

Radio::Radio()
{
    _connect_to_network();
}

bool Radio::_connect_to_network()
{
    WiFi.begin(_wifi_cred.ssid, _wifi_cred.pwd);
    while (WiFi.status() != WL_CONNECTED){ delay(250); }
}


void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); 
    
    Radio radio = Radio();

    blink_sequence();
}

void loop()
{
    Serial.println("test");
    delay(1000);
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