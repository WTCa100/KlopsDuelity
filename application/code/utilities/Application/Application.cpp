#include <iostream>

#include "Application.hpp"
#include "../../game/Menu/Menu.hpp"

Application::Application()
{
    std::cout << "Application :ctor:\n";
    Menu* test = new Menu;
    delete test;
}

Application::~Application()
{
    std::cout << "Application :dtor:\n";
}
