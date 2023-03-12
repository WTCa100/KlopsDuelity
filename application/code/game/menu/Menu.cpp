#include <iostream>

#include "./Menu.hpp"
#include "../entities/heu/heu.hpp"
#include "../entities/heu/shooter/shooter.hpp"
#include "../entities/weaponry/weapons.hpp"
#include "../entities/weaponry/muskets/Springfield1835/springfield1835.hpp"

Menu::Menu()
{
    std::cout << "Menu :ctor:\n";
}

Menu::~Menu()
{
    std::cout << "Menu :dtor:\n";
}

void Menu::startGame()
{
    // This is due to be changes - it's now a simple show of functions
    //entity::shooter* enemy = new entity::shooter();
    //entity::shooter* player = new entity::shooter(true);
    //std::cout << "Shooters! Present weapons!";
    //enemy->showWeapon();
    //player->showWeapon();
    //delete enemy;
    //delete player;

}