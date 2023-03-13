#include <iostream>

#include "Application.hpp"
#include "../../game/Menu/Menu.hpp"
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
    Session* gameSession = new Session;
    gameSession->characterCreation();
    gameSession->duel();
    delete gameSession;
    // Create session
}

Application::~Application()
{
    std::cout << "Application :dtor:\n";
}

Application* Application::instance_ = nullptr;