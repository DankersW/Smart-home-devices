#ifndef RADIO_H
#define RADIO_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>


class Radio 
{
    private:
        struct Credentials
        {
            const char* ssid = "SaveOurWinters";
            const char* pwd =  "prettyflyforawifi";
        } _wifi_cred;
        struct Mqtt_details
        {
            const char* broker = "192.168.1.140";
            const int port = 1883;
            const char* device_id = "dev_001";
        } _mqtt_info;

        WiFiClient _wifi_client;
        PubSubClient _mqtt_client;

        bool connect_to_network();
        bool connect_to_mqtt_broker();

        void mqtt_msg_received(char* topic, byte* payload, unsigned int length);
        void check_radio_status(void);
        
    public:
        Radio();
        ~Radio(){}
        void begin();
        void loop();
        bool publish(const char* topic, const char* payload);
};

#endif