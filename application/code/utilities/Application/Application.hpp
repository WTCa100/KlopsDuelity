#pragma once

#include "../Toolbox/FileManager/Fmanager.hpp"

class Application
{
// TODO:
/*
1. Add Checking of the directories
2. Add config building
3. Load/save from config
Note: this time config should be stored in different file with specified extension
*/

private:
    FManager* fMgr_;
    static Application* instance_;
    Application();
    void startGameSession();
public:
    void startApp();
    static Application* getInstance();
    ~Application();
};

