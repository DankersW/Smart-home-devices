#include "catch.hpp"
#include "serializer.h"
#include "types.h"


TEST_CASE("Testing the Serializer class")
{
    Serializer serializer = Serializer();
    
    SECTION("Test to_json")
    {
        SECTION("Test set 2: digit precision")
        {
            SensorData test_data = {12.04, 33.00};
            std::string correct = "{\"temperature\": 12.04, \"humidity\": 33.00}";
            std::string result = serializer.to_json(test_data);
            REQUIRE(correct == result);
        }

        SECTION("Test set 2: no precision")
        {
            SensorData test_data = {12, 33};
            std::string correct = "{\"temperature\": 12.00, \"humidity\": 33.00}";
            std::string result = serializer.to_json(test_data);
            REQUIRE(correct == result);
        }
    }
}