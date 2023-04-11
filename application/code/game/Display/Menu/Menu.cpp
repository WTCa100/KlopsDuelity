#include <iostream>

#include <ncurses.h>

#include "./Menu.hpp"

// Get toolbox methods
#include "../../../utilities/Toolbox/InputCheck/InputCheck.hpp"
#include "../../../utilities/IOStream/NIO.hpp"

// Get enities
#include "../../Entities/HEU/heu.hpp"
#include "../../Entities/HEU/Shooter/shooter.hpp"

Menu::Menu() : actionChoosen_(MenuOptions::kNone)
{
    printw("Menu :ctor:\n");
}

void Menu::mainDisplay()
{
    std::string userInput("");
    printw("Welcome to Klops Duelit!\n");
    printw("---- Main Menu ----\n");
    printw("1. Game\n");
    printw("2. Exit\n");          
    printw("------------------ \n");
    printw("Option: ");
    while(!getUserInput(userInput))
    {
        printw("Please provide a valid answer\n");
        printw("Press any key to continue...\n");
        getch();
        clear();
        printw("Welcome to Klops Duelit!\n");
        printw("---- Main Menu ----\n");
        printw("1. Game\n");
        printw("2. Exit\n");        
        printw("------------------ \n");     
        printw("Option: ");               
    }
    // Assign it to the action
    actionChoosen_ = static_cast<MenuOptions>(std::stoi(userInput));

}

bool Menu::getUserInput(std::string& userInput)
{
    NI::getline(userInput);
    return InputCheck::isStringNumberInRange(userInput, 2);
}

Menu::~Menu()
{
    printw("Menu :dtor:\n");
}