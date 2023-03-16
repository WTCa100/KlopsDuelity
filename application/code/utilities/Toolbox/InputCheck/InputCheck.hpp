#pragma once

#include <string>

class InputCheck
{
private:
    /* data */
public:
    static std::string helperInsertInputIntoContainer(std::string& container);
    static bool isStringNumber(const std::string& input);
    static bool isStringNumberInRange(const std::string& input, int maxVal, int minVal = 1);
};
