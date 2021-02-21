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

#endif
