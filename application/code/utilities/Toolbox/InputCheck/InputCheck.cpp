#include "./InputCheck.hpp"

// Get ncurses methods
#include <ncurses.h>
#include "../../IOStream/NIO.hpp" // For NI::getline()

#include <sstream>
#include <iostream>
#include <algorithm>

bool InputCheck::isStringNumber(const std::string& input)
{
    printw("Checking if string is a number...\n");
    return !input.empty() && input.find_first_not_of("0123456789") == std::string::npos;
}

/// @brief This function is used mainly to assing user inputed value into a string container for classes that are not relying on 
/// @param container 
/// @return the same container with assigned value
std::string InputCheck::helperInsertInputIntoContainer(std::string& container)
{
    NI::getline(container);    
    return container;
}

bool InputCheck::isStringNumberInRange(const std::string& input, int maxVal, int minVal)
{
    if(!isStringNumber(input))
    {
        return false;
    }

    int stringNumericValue = std::stoi(input);

    return stringNumericValue >= minVal && stringNumericValue <= maxVal;

}