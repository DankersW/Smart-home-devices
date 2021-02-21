#include "catch.hpp"
#include "serializer.h"

TEST_CASE("Testing the simple Math module")
{
    //SimpleMath simple_math = SimpleMath();
    Serializer seri = Serializer();
    
    SECTION("Test simple ADD")
    {
        //int sum = simple_math.add(1,2);
        //REQUIRE(sum == 3);

        //sum = simple_math.add(2,2);
        REQUIRE(4 == 4);
        REQUIRE(seri.get() == 2);
    }
}