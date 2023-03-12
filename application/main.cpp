#include <iostream>

#include "./code/utilities/Application/Application.hpp"
#include "./code/game/Entities/Weapons/Muskets/Springfield1835/springfield1835.hpp"
int main()
{
    springfield1835 testWeapon;
    testWeapon.present();
    std::cout << "Hello world!\n";
    Application* gameApp = new Application;
    delete gameApp;    
    return 0;
}
