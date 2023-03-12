#include <iostream>

#include "Application.hpp"
#include "../../game/Menu/Menu.hpp"

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

void Application::displayMenu()
{
    Menu* test = new Menu;
    // display menu
    test->startGame();
    delete test;
}


Application::~Application()
{
    std::cout << "Application :dtor:\n";
}

Application* Application::instance_ = nullptr;