#include "./player.hpp"

// get toolbox
#include "../../utilities/Toolbox/InputCheck/InputCheck.hpp"

Player::Player(std::string name) : Shooter(true, name), money_(100), pOrigin_(choosePlayerOrigin())
{
    initStatEvaluation();
    std::cout << "Player created\n";
}

Player::~Player()
{
    std::cout << "Player despawned\n";
}

/// @brief At creation of player instance assign values that are unique to it's origin
void Player::initStatEvaluation()
{
    switch (pOrigin_)
    {
    case PlayerOrigin::kBasicAim:
        statAim_ = 3;
        break;
    case PlayerOrigin::kBasicVitality:
        statVitality_ = 3;
    case PlayerOrigin::kBasicCharisma:
        statCharisma_ = 3;
    default:
        break;
    }
}

PlayerOrigin Player::choosePlayerOrigin()
{
    std::string userInput("");
    // Later we will make stories now we will only operate on debug values
    std::cout << "What is thy story!\n";
    std::cout << "1 I was kBasicAim as a child!\n";
    std::cout << "2 I was kBasicVitality as a child!\n";
    std::cout << "3 I was kBasicCharisma as a child!\n";
    while(!InputCheck::isStringNumberInRange(InputCheck::helperInsertInputIntoContainer(userInput), 3));
    {
        std::cout << "Please enter valid option!\n";
    }

    return static_cast<PlayerOrigin>(std::stoi(userInput));
}