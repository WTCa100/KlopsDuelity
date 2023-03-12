#include <iostream>

#include "./Menu.hpp"

// Get enities
#include "../Entities/HEU/heu.hpp"
#include "../Entities/HEU/Shooter/shooter.hpp"

Menu::Menu()
{
    std::cout << "Menu :ctor:\n";
}

void Menu::startGame()
{
    entities::HEUTypes::Shooter* enemy = new entities::HEUTypes::Shooter;
    entities::HEUTypes::Shooter* player = new entities::HEUTypes::Shooter;
    enemy->presentWeapon();
    player->presentWeapon();

    delete enemy; delete player;

}

Menu::~Menu()
{
    std::cout << "Menu :dtor:\n";
}