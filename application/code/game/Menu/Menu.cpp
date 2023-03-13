#include <iostream>

#include "./Menu.hpp"

// Get enities
#include "../Entities/HEU/heu.hpp"
#include "../Entities/HEU/Shooter/shooter.hpp"

Menu::Menu()
{
    std::cout << "Menu :ctor:\n";
}

void Menu::mainDisplay()
{
    std::cout << "Welcome to Klops Duelit!\n";
    std::cout << "What do you want to do\n";
    std::cout << "Lmao you can't choose xD\n";
    std::cin.ignore();
}

Menu::~Menu()
{
    std::cout << "Menu :dtor:\n";
}