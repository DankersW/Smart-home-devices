
#include "serializer.h"

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
