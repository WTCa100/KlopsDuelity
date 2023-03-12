#include <iostream>

#include "./code/utilities/Application/Application.hpp"
#include "./code/game/Entities/Weapons/Muskets/Springfield1835/springfield1835.hpp"
#include "./code/game/Entities/HEU/heu.hpp"
#include "./code/game/Entities/HEU/Shooter/shooter.hpp"

int main()
{
    std::cout << "Hello world!\n";
    Application* gameApp = new Application;
    delete gameApp;    
    return 0;
}
