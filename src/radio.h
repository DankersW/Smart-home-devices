#ifndef RADIO_H
#define RADIO_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

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
        Radio(){}
        ~Radio(){}
        void begin();
};

#endif