#include <iostream>

#include "Application.hpp"
#include "../../game/Display/Menu/Menu.hpp"
#include "../../game/Session/session.hpp"

#include <ncurses.h>

Application::Application()
{
    printw("Application :ctor:\n");
    refresh();
}

Application* Application::getInstance()
{
    if(instance_)
    {
        return instance_;
    }
    else
    {
        instance_ = new Application;
        return instance_;
    }
}

void Application::startGameSession()
{
}

void Application::startApp()
{
    // TODO: get config
    // Get menu display
    Menu* mainMenu = new Menu;
    mainMenu->mainDisplay();
    // If statements for now - change to switch later
    if(mainMenu->getActionChoosen() == MenuOptions::kStartGame || mainMenu->getActionChoosen() == MenuOptions::kNone)
    {
        Session* gameSession = new Session(fMgr_);
        gameSession->core();
        delete gameSession;
    }
    else // Close app
    {
        printw("Application closing\n");
        refresh();
        delete mainMenu;                
        return;
    }

    if(mainMenu)
    {
        delete mainMenu;
    }
}

Application::~Application()
{
    printw("Application :dtor:\n");
    delete fMgr_;
}

Application* Application::instance_ = nullptr;