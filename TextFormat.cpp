#include "TextFormat.h"
#include <sstream>

std::vector<std::string> split(const std::string& str, const char& delimiter)
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;
    while (getline(ss, item, delimiter))
    {
        result.push_back(item);
    }
    return result;
}

std::string to_lower(const std::string& str)
{
    std::string result = str;
    for (char& c : result)
    {
        c += 32 * (c >= 'A' && c <= 'Z');
    }
    return result;
}

std::string to_upper(const std::string& str)
{
    std::string result = str;
    for (char& c : result)
    {
        c = c - 32 * (c >= 'a' && c <= 'z');
    }
    return result;
}
