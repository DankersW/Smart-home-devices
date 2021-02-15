#include "sensor.h"

Sensor::Sensor() : _dht(_pin_dht11, _type_dht)
{
    _dht.begin();
}

Sensor::~Sensor()
{
}

float Sensor::get_temperature()
{
    return _data.temp;
}

float Sensor::get_humidity()
{
    return _data.humi;
}

Sensor::SensorData Sensor::read()
{
    _data.temp = _dht.readTemperature();
    _data.humi = _dht.readHumidity();

    return _data;
}