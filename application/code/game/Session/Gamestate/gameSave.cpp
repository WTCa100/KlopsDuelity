#include "./gameSave.hpp"

#include "../../../utilities/IOStream/NIO.hpp"
#include <ncurses.h>

gameSave::gameSave(FManager* fMgr) : fMgr_(fMgr)
{
    // Creation of save file
    std::string rawName = "";
    bool startSession = false; 
    while(!startSession)
    {
        printw("Name of the save file: ");
        NI::getline(rawName);
        if(fMgr_->isFileGood(rawName))
        {
            printw("Save file already exists!");
            getch();
            clear();
        }
        else
        {
            fMgr_->createFile(rawName);
            if(!fMgr_->isFileGood(rawName))
            {
                printw("Could not create a save file called %s!\n", rawName.c_str());
            }
            else
            {
                startSession = true;
            }
        }
    }
}

gameSave::~gameSave()
{
}
