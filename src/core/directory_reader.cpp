#include "directory_reader.hpp"

#include <filesystem>

namespace octo::core
{
DirectoryReader::DirectoryReader(std::string_view path)
{
    path_ = path;
}
std::vector<std::string> DirectoryReader::list()
{
    for (const auto &entry : std::filesystem::directory_iterator(path_))
        result.push_back(entry.path());
    return result;
}
} // namespace octo::core
