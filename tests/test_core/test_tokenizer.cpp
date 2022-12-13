#include "tokenizer.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

using namespace octo::core;
namespace
{
const std::unordered_set<std::string> STOPWORDS = {"car", "bus"};
}
TEST_CASE("Tokenizer test")
{
    Tokenizer tokenizer(STOPWORDS);
    SECTION("List function")
    {
        REQUIRE(tokenizer.list("car; cat, dog; ") == std::vector<std::string>{"cat", "dog"});
    }
}
