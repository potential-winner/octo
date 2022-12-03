#pragma once

#include <cstddef>
#include <memory>
#include <string>

namespace octo::core
{

struct Document {
    size_t id;
    std::string path;
};

using DocumentPtr = std::shared_ptr<Document>;

} // namespace octo::core
