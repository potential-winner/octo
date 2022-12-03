#include "inverted_index.hpp"

#include <catch2/catch_test_macros.hpp>
#include <stdexcept>

using namespace octo::core;

TEST_CASE("Test inverted index new")
{
    InvertedIndex index;

    auto doc = std::make_shared<Document>();
    SECTION("insert items")
    {
        REQUIRE_NOTHROW(index.Insert(doc, {"car", "blue", "something", "follow"}));
    }

    SECTION("find")
    {
        REQUIRE_NOTHROW(throw std::runtime_error("womeasdfa"));
    }
}
