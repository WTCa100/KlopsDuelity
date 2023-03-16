#include "./InputCheck.hpp"

#include <sstream>
#include <algorithm>

bool InputCheck::isStringNumber(const std::string& input)
{
    return !input.empty() && input.find_first_not_of("0123456789") == std::string::npos;
}