#include "radio.h"

Radio::Radio()
{
    //_mqtt_client(this->_espClient);
}

void Radio::begin()
{
    //_mqtt_client(WiFiClient _espClient);
    connect_to_network();
    connect_to_mqtt_broker();
}

bool Radio::connect_to_network()
{
    WiFi.begin(_wifi_cred.ssid, _wifi_cred.pwd);
    while (WiFi.status() != WL_CONNECTED){ delay(250); }
    return true;
}

bool Radio::connect_to_mqtt_broker()
{
    _mqtt_client.setServer(_mqtt_info.broker, _mqtt_info.port);

    _mqtt_client.setCallback([this](char* topic, byte* payload, unsigned int length) {
        this->mqtt_msg_received(topic, payload, length);
    });

    while (!_mqtt_client.connected()){ delay(250); }
    return true;
}

void Radio::mqtt_msg_received(char* topic, byte* payload, unsigned int length)
{
}
