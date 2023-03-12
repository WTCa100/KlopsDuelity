#include <iostream>

#include "./code/utilities/Application/Application.hpp"

int main()
{
    std::cout << "Hello world!\n";
    Application* gameApp = Application::getInstance();
    gameApp->displayMenu();
    delete gameApp;    
    return 0;
}
