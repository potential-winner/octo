#include "indexing.hpp"
#include <string>
#include <string_view>
#include <vector>

namespace octo::core
{
std::vector<std::string> DirectoryReader::read_stopwords()
{
    std::ifstream file("src/core/STOPWORDS.txt");
    std::vector<std::string> STOPWORDS;
    std::string str;
    while (file >> str) {
        STOPWORDS.push_back(str);
    }
    return STOPWORDS;
}

DirectoryReader::DirectoryReader(std::string_view path)
{
    path_ = path;
}
std::vector<std::string> DirectoryReader::list()
{
    for (const auto &entry : std::filesystem::directory_iterator(path_))
        DirectoryReader::result.push_back(entry.path());
    return result;
}

FileTokenizer::FileTokenizer(std::string_view path)
{
    path_ = path;
}

// std::vector<std::string> FileTokenizer::list()
// {
    
// }
} // namespace octo::core
