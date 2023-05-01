#include "./Fmanager.hpp"

#include <sys/stat.h>
#include <ncurses.h>
#include <experimental/filesystem>
#include <fstream>

bool FManager::isDirectoryGood(const std::string& path)
{
    struct stat buffer;
    printw("Creating path %s\n", path.c_str());
    return (stat(path.c_str(), &buffer) == 0);
}

void FManager::createDirectory(const std::string& path)
{
    printw("Checking if path %s\n", path.c_str());
    uint16_t tryCounter = 1;
    std::experimental::filesystem::path fsPath(path);
    while(tryCounter <= 5)
    {
        printw("Attempt %d\n", tryCounter);
        std::experimental::filesystem::create_directories(fsPath);
        if(!isDirectoryGood(path))
        {
            tryCounter++;
            printw("Failed\n");
        }
        else
        {
            break;
        }
    }
    printw("Succesfully created directory %s\n", path.c_str());
}

bool FManager::isFileGood(const std::string& fileName, const std::string& path)
{
    if(fileName.empty())
    {
        return false;
    }
    
    std::ifstream checkFile(path + "/" + fileName);
    return checkFile.good();
}

void FManager::createFile(const std::string& fileName, const std::string& path)
{
    printw("Creating file %s at %s\n", fileName.c_str(), path.c_str());
    const std::string finalFileName = path + "/" + fileName;
    std::ofstream makeFile;
    uint16_t tryCounter = 1;
    while(tryCounter <= 5)
    {
        printw("Attempting to create %s (attempt %d)\n", finalFileName.c_str(), tryCounter);
        makeFile.open(finalFileName);
        if(!makeFile.is_open())
        {
            tryCounter++;
            printw("Failed!\n");
        }
        else
        {
            break;
        }
    }

    printw("Succesfully created %s at %s\n", fileName.c_str(), path.c_str());
}