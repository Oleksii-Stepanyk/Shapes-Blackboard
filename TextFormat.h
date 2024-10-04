#pragma once
#include <string>
#include <vector>

namespace TextFormat
{
    static std::vector<std::string> split(const std::string&, const char&);
    static std::string to_lower(const std::string&);
    static std::string to_upper(const std::string&);
}
