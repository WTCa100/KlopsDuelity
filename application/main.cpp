#include <iostream>
#include <ctime>

#include "./code/utilities/Application/Application.hpp"

int main()
{
    srand(time(NULL));
    std::cout << "Hello world!\n";
    Application* gameApp = Application::getInstance();
    // Check files
    // Start app
    gameApp->startApp();
    delete gameApp;    
    return 0;
}
