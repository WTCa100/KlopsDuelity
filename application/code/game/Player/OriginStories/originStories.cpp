#include <string>
#include <iostream>

#include "./originStories.hpp"

// Get toolbox
#include "../../../utilities/Toolbox/InputCheck/InputCheck.hpp"

Origin::Origin() : startingOrigin_(choosePlayerOrigin())
{
    std::cout << "Creation of origin player story\n";
    initStatAssign();
}

void Origin::initStatAssign()
{

    switch (startingOrigin_)
    {
    case PlayerOrigin::kBasicAim:
        baseOriginStatAim_ = 3;
        baseOriginStatCharisma_ = 1;
        baseOriginStatVitality_ = 1;
        break;
    case PlayerOrigin::kBasicCharisma:
        baseOriginStatAim_ = 1;
        baseOriginStatCharisma_ = 3;
        baseOriginStatVitality_ = 1;
        break;
    case PlayerOrigin::kBasicVitality:
        baseOriginStatAim_ = 1;
        baseOriginStatCharisma_ = 1;
        baseOriginStatVitality_ = 3;
        break;
    default:
        std::cout << "Cannot find specified origin - assigning default values\n";
        baseOriginStatAim_ = 0;
        baseOriginStatCharisma_ = 0;
        baseOriginStatVitality_ = 0;
        break;
    }

}

PlayerOrigin Origin::choosePlayerOrigin()
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
    std::cout << "Good outcome\n";
    std::cin.ignore();
    return static_cast<PlayerOrigin>(std::stoi(userInput));
}