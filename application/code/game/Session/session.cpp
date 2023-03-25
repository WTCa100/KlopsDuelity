#include "./session.hpp"

// Get ncruses
#include <ncurses.h>
#include "../../utilities/IOStream/NIO.hpp"

#include "../Entities/HEU/Shopkeeper/shopkeeper.hpp"

Session::Session() : mainCharacter_(nullptr), fighting_(nullptr)
{
    printw("Session starts\n");
}

Session::~Session()
{
    // When the real game will be implemented we will parse entity lists and destroy them
    // Excempt player weapons.
    printw("Teardown\n");
    for(auto entity : heuCount_)
    {
        printw("Teardown entity\n");
        delete entity;
    }

    printw("Session ends\n");
}

void Session::characterCreation()
{
    std::string playerName;
    printw("Enter your name!\n");
    NI::getline(playerName);
    printw("%s name - %d length\n", playerName.c_str(), playerName.length());
    getch();
    mainCharacter_ = new Player(playerName);
}

void Session::shop()
{
    entities::HEUTypes::Shopkeeper* shopOwner = new entities::HEUTypes::Shopkeeper(mainCharacter_);
    shopOwner->act();
    delete shopOwner;
}

void Session::core()
{
    characterCreation();
    bool gameOn = true;
    Menus::SessionMainScreen* mainSessionDisplay = new Menus::SessionMainScreen();
    while(gameOn)
    {
        mainSessionDisplay->mainDisplay();
        switch (mainSessionDisplay->getActionChoosen())
        {
        case SessionMainScreenOptions::kGoToArena:
            duel();
            break;
        case SessionMainScreenOptions::kGoToShop :
            shop();        
            break;
        case SessionMainScreenOptions::kQuit :
            gameOn = false;
            break;
        }
    }

    delete mainSessionDisplay;
}

void Session::duel()
{
    printw("!-- Debug prepare variables for duel\n");
    entities::HEUTypes::Shooter* enemy = new entities::HEUTypes::Shooter(false, "RandomName");
    heuCount_.push_back(enemy); heuCount_.push_back(mainCharacter_);
    fighting_ = new Duel(mainCharacter_, enemy);
    fighting_->prepareForFight();
    fighting_->shootOut();

    // After game show health of the oponents
    printw("!-- Debug player character health: %.2f\n", mainCharacter_->getHealth());
    printw("!-- Debug Enemy character health: %.2f\n", enemy->getHealth());

    printw("Duel ends!\n");
    
}