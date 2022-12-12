#pragma once

#include "inverted_index.hpp"
#include <filesystem>
#include <fstream>
#include <string>
#include <string_view>

namespace octo::core
{
class DirectoryReader
{
  private:
    std::string_view path_;

  public:
    DirectoryReader(std::string_view path);
    std::vector<std::string> result;
    std::vector<std::string> read_stopwords();
    std::vector<std::string> list(); // returns all file paths from directory
};

class FileTokenizer
{
  private:
    std::string_view path_;

  public:
    FileTokenizer(std::string_view path);

    std::vector<std::string> list(); // returns all words without whitespaces, without stopwords
};
} // namespace octo::core
