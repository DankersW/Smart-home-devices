#include "sensor.h"

Sensor::Sensor()
{
    _dht = new DHT(_pin_dht11, _type_dht);
}

Sensor::~Sensor()
{
}

void Sensor::begin()
{
    _dht->begin();
}

SensorData Sensor::poll()
{
    _data.temp = _dht->readTemperature();
    _data.humi = _dht->readHumidity();
    return _data;
}
