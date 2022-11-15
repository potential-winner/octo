#pragma once

#include "document.hpp"

#include <optional>
#include <unordered_map>
#include <vector>

namespace octo::core
{
using Documents = std::vector<DocumentPtr>;

struct InvertedIndex {

    InvertedIndex() = default;

    void Insert(DocumentPtr document, const std::vector<std::string> &tokens);
    Documents Find(const std::string &token);

  private:
    std::unordered_map<std::string, Documents> index;
};

} // namespace octo::core
