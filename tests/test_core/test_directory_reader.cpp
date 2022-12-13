#include "directory_reader.hpp"

#include <catch2/catch_test_macros.hpp>
#include <filesystem>
#include <fstream>
#include <random>
#include <string>

using namespace octo::core;
namespace fs = std::filesystem;

namespace
{
std::string random_string(std::string::size_type length)
{
    constexpr char allowed_symbols[] = "0123456789"
                                       "abcdefghijklmnopqrstuvwxyz";

    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(allowed_symbols) - 2);
    std::string s;
    s.reserve(length);
    while (length--)
        s += allowed_symbols[pick(rg)];
    return s;
}
} // namespace

struct TempDirWithFiles {
    fs::path path;
    std::vector<std::string> files;
    TempDirWithFiles()
        : path(fs::temp_directory_path() / random_string(12))
    {
        fs::create_directory(path);
        for (int i = 0; i < 5; ++i) {
            createFile();
        }
    }
    fs::path createFile()
    {
        fs::path file_path = path / (random_string(12) + ".txt");
        std::ofstream file(file_path.string());
        file << random_string(12);
        files.push_back(file_path.string());
        return file_path;
    }
    ~TempDirWithFiles()
    {
        std::filesystem::remove_all(path);
    }
};

TEST_CASE("Directory reader test")
{
    TempDirWithFiles temp_dir;
    DirectoryReader reader(temp_dir.path.string());
    SECTION("List function")
    {
        REQUIRE(reader.list() == temp_dir.files);
    }
}
