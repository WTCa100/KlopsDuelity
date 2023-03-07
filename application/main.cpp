#include <iostream>

#include "./code/utilities/AppMgmt/Application.hpp"
int main()
{
    std::cout << "Hello world!\n";
    Application* gameApp = new Application;
    delete gameApp;    
    return 0;
}