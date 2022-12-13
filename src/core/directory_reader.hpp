#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace octo::core
{
class DirectoryReader
{
  private:
    std::string_view path_;

  public:
    DirectoryReader(std::string_view path);
    std::vector<std::string> result;
    std::vector<std::string> list(); // returns all file paths from directory
};
} // namespace octo::core
