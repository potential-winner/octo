#pragma once

#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

namespace octo::core
{
class Tokenizer
{
  private:
    std::unordered_set<std::string> stopwords;

  public:
    Tokenizer(std::unordered_set<std::string> stopwords);
    std::vector<std::string> list(std::string_view text); // returns all words without whitespaces, without stopwords
};
} // namespace octo::core
