#include "./session.hpp"

#include "../Entities/HEU/Shopkeeper/shopkeeper.hpp"

Session::Session() : mainCharacter_(nullptr), fighting_(nullptr)
{
    std::cout << "Session starts\n";
}

Session::~Session()
{
    // When the real game will be implemented we will parse entity lists and destroy them
    // Excempt player weapons.
    std::cout << "Teardown\n";
    for(auto entity : heuCount_)
    {
        std::cout << "Teardown entity: \n";
        delete entity;
    }

    std::cout << "Session ends\n";
}

void Session::characterCreation()
{
    std::string playerName;
    std::cout << "Enter you name!\n";
    std::getline(std::cin, playerName);
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
    std::cout << "!-- Debug prepare variables for duel\n";
    entities::HEUTypes::Shooter* enemy = new entities::HEUTypes::Shooter(false, "RandomName");
    heuCount_.push_back(enemy); heuCount_.push_back(mainCharacter_);
    fighting_ = new Duel(mainCharacter_, enemy);
    fighting_->prepareForFight();
    fighting_->shootOut();

    // After game show health of the oponents
    std::cout << "!-- Deubg main character health: " << mainCharacter_->getHealth() << std::endl;
    std::cout << "!-- Deubg enemy character health: " << enemy->getHealth() << std::endl;

    std::cout << "!!Duel ends!!\n";
    
}