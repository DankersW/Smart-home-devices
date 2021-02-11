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
        struct mqtt_details
        {
            const char* broker = "192.168.1.125";
            const int port = 1883;
        } _mqtt_info;

        WiFiClient _espClient;
        PubSubClient _mqtt_client;

        bool connect_to_network();
        bool connect_to_mqtt_broker();
        
    public:
        Radio();
        ~Radio(){}
        void begin();
        void callback(char* topic, unsigned char* payload, unsigned int length);

};

#endif