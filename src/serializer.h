#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "types.h"

class Serializer
{
private:
    
public:
    Serializer();
    ~Serializer();
    const uint8_t* to_byte_array(SensorData sensor_data);
    std::string to_string();
};

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

const uint8_t* Serializer::to_byte_array(SensorData sensor_data)
{
    // todo: get length
    static const uint8_t buffer[] = { 5, 7, 3, 4, 9, 1, 3 };
    return buffer;
}

std::string Serializer::to_string()
{
    std::string hello = "hello";
    return hello;
}

#endif