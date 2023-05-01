#pragma once

// Player
// Entities list
// Toolbox
#include "../../../utilities/Toolbox/FileManager/Fmanager.hpp"
// Weaponry 
#include <string>

class gameSave
{
private:
    FManager* fMgr_;
    std::string saveName;
public:
    void createSaveFile();
    void updateSaveFile();
    gameSave(FManager* fMgr);
    ~gameSave();
};