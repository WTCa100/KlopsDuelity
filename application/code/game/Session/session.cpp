#include "./session.hpp"

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