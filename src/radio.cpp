#include "radio.h"


void Radio::begin()
{
    bool connected = _connect_to_network();
}

bool Radio::_connect_to_network()
{
    WiFi.begin(_wifi_cred.ssid, _wifi_cred.pwd);
    while (WiFi.status() != WL_CONNECTED){ delay(250); }
    return true;
}