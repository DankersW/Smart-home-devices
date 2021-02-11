#include "radio.h"

Radio::Radio()
{
    _mqtt_client(_espClient);
}

void Radio::begin()
{
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
    _mqtt_client.setCallback(Radio::callback);
    while (!_mqtt_client.connected()){ delay(250); }
    return true;
}

void Radio::callback(char* topic, byte* payload, unsigned int length)
{
}
