#include "LRUcache.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace octo::core;

TEST_CASE("Test LRU cache")
{
    LRUcache LRU(2);
    LRU.put(1, 1);
    LRU.put(2, 2);
    SECTION("Put items")
    {
        REQUIRE_NOTHROW(LRU.put(1, 1));
        REQUIRE_NOTHROW(LRU.put(2, 2));
    }
    SECTION("Get items")
    {
        REQUIRE(LRU.get(1) == 1);
        REQUIRE(LRU.get(2) == 2);
    }
}
