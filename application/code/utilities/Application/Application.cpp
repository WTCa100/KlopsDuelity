#include <iostream>

#include "Application.hpp"
#include "../../game/Display/Menu/Menu.hpp"
#include "../../game/Session/session.hpp"


Application::Application()
{
    std::cout << "Application :ctor:\n";
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
        Session* gameSession = new Session;
        gameSession->characterCreation();
        gameSession->duel();
        delete gameSession;
    }
    else // Close app
    {
        std::cout << "Closing\n";
        return;
    }

    // Create session
}

Application::~Application()
{
    std::cout << "Application :dtor:\n";
}

Application* Application::instance_ = nullptr;