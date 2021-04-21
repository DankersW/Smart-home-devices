#include "radio.h"

Radio::Radio() : _mqtt_client(_wifi_client)
{
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

    _mqtt_client.setCallback([this](char* topic, byte* payload, unsigned int length) {
        this->mqtt_msg_received(topic, payload, length);
    });

    while (!_mqtt_client.connected())
    {
        _mqtt_client.connect(_mqtt_info.device_id);
        delay(250); 
    }
    _mqtt_client.subscribe("iot/#");
    return true;
}

void Radio::mqtt_msg_received(char* topic, byte* payload, unsigned int length)
{
    Serial.println("message received");
}

void Radio::loop()
{
    _mqtt_client.loop();
}

void Radio::check_radio_status(void)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        connect_to_network();
    }
    if (!_mqtt_client.connected())
    {
        connect_to_mqtt_broker();
    }
}

bool Radio::publish(const char* topic, const char* payload)
{
    check_radio_status();
    return _mqtt_client.publish(topic, payload);
}
