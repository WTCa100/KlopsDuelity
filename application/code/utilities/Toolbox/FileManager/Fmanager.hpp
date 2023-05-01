#pragma once

#include <string>

class FManager
{
    public:
    // Check for folder
    bool isDirectoryGood(const std::string& path);
    void createDirectory(const std::string& path);
    bool isFileGood(const std::string& fileName, const std::string& path = ".");
    void createFile(const std::string& fileName, const std::string& path = ".");

    FManager() = default;
    ~FManager() = default;
};