#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "types.h"
#include <sstream>

class Serializer
{
private:
    std::string cast_to_string(float value, int precision);
public:
    Serializer();
    ~Serializer();
    std::string to_json(SensorData sensor_data);
};

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

std::string Serializer::cast_to_string(float value, int precision=2)
{
    std::ostringstream string_stream;
    string_stream.precision(precision);
    string_stream << std::fixed << value;
    return string_stream.str();
}

std::string Serializer::to_json(SensorData data)
{
    std::string json = "{";
    json += "\"temperature\": " + cast_to_string(data.temp) + ", ";
    json += "\"humidity\": " + cast_to_string(data.humi);
    json += "}";

    return json;
}   

#endif