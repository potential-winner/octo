#include "tokenizer.hpp"

#include <string>
#include <string_view>
#include <vector>

namespace octo::core
{
Tokenizer::Tokenizer(std::unordered_set<std::string> stopwords)
    : stopwords(std::move(stopwords))
{
}

std::vector<std::string> Tokenizer::list(std::string_view text)
{
    std::vector<std::string> tokens;
    std::string current_token;
    for (char c : text) {
        if (std::isalnum(c)) {
            current_token.push_back(c);
        } else if (current_token.empty()) {
            continue;
        } else {
            if (stopwords.count(current_token) == 0) {
                tokens.push_back(std::move(current_token));
            }
            current_token = {};
        }
    }
    return tokens;
    // std::ifstream in_file;
    // std::ifstream in_stopwords;
    // in_file.open("/home/iskandar/projects/octo/octo/src/contents/test_article.txt");
    // in_stopwords.open("/home/iskandar/projects/octo/octo/src/contents/STOPWORDS.txt");
    // if (in_file.is_open()) {
    //     while (in_file.good()) {
    //         std::getline(in_file, current_line, ',');
    //         std::stringstream ss(current_line);
    //         while (std::getline(ss, current_line, ' ')) {
    //             if (!current_line.empty()) {
    //                 tokens.push_back(current_line);
    //             }
    //         }
    //     }
    //     in_file.close();
    // } else {
    //     throw std::runtime_error("Could not open article file");
    // }
    // for (std::string item : tokens) {
    //     std::ofstream outfile("/home/iskandar/projects/octo/octo/src/contents/test_article_updated.txt");
    //     if (in_stopwords.is_open()) {
    //         while (in_stopwords.good()) {
    //             std::getline(in_stopwords, current_stopword, ',');
    //             if (item != current_stopword) {
    //                 outfile << item << std::endl;
    //             }
    //         }
    //         outfile.close();
    //         in_stopwords.close();
    //     } else {
    //         throw std::runtime_error("Could not open STOPWORDS file");
    //     };
    // }
    // return tokens;
}
} // namespace octo::core
