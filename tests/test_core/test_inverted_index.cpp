#include "inverted_index.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace octo::core;

TEST_CASE("Test inverted index")
{
    InvertedIndex index;

    auto doc = std::make_shared<Document>();
    SECTION("insert items")
    {
        REQUIRE_NOTHROW(index.Insert(doc, {"car", "blue", "something", "follow"}));
    }
}
