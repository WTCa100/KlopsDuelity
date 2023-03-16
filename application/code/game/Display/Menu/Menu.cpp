#include <iostream>


#include "./Menu.hpp"

// Get toolbox methods
#include "../../../utilities/Toolbox/InputCheck/InputCheck.hpp"

// Get enities
#include "../../Entities/HEU/heu.hpp"
#include "../../Entities/HEU/Shooter/shooter.hpp"

Menu::Menu() : actionChoosen_(MenuOptions::kNone)
{
    std::cout << "Menu :ctor:\n";
}

void Menu::mainDisplay()
{
    std::string userInput("");
    std::cout << "Welcome to Klops Duelit!\n";
    std::cout << "---- Main Menu ----\n";
    std::cout << "1. Game\n";
    std::cout << "2. Exit\n";
    while(!getUserInput(userInput))
    {
        std::cout << "Please provide a valid answer\n";
    }
    
    // Assign it to the action
    actionChoosen_ = static_cast<MenuOptions>(std::stoi(userInput));

}

bool Menu::getUserInput(std::string& userInput)
{
    std::getline(std::cin, userInput);
    return InputCheck::isStringNumber(userInput);
}

Menu::~Menu()
{
    std::cout << "Menu :dtor:\n";
}