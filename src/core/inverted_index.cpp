#include "inverted_index.hpp"

namespace octo::core
{

void InvertedIndex::Insert(DocumentPtr document, const std::vector<std::string> &tokens)
{
    for (const auto &token : tokens) {
        auto it = index.find(token);
        if (it == index.end()) {
            index.emplace(token, std::vector{std::move(document)});
        } else {
            it->second.emplace_back(std::move(document));
        }
    }
}

Documents InvertedIndex::Find(const std::string &token)
{
    auto it = index.find(token);
    if (it != index.end()) {
        return it->second;
    }
    return {};
}

} // namespace octo::core
