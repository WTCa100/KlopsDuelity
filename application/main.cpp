#include <iostream>

#include "./code/utilities/Application/Application.hpp"
int main()
{
    std::cout << "Hello world!\n";
    Application* gameApp = new Application;
    delete gameApp;    
    return 0;
}
