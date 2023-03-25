#include <string>
#include <ncurses.h>

#include "./originStories.hpp"

// Get toolbox
#include "../../../utilities/Toolbox/InputCheck/InputCheck.hpp"

Origin::Origin() : startingOrigin_(choosePlayerOrigin())
{
    printw("Creation of player story\n");
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
        printw("Cannot find specified origin - assigning default values\n");
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
    printw("What is thy story!\n");
    printw("1 I was kBasicAim as a child!\n");
    printw("2 I was kBasicVitality as a child!\n");
    printw("3 I was kBasicCharisma as a child!\n");
    while(true)
    {
        InputCheck::helperInsertInputIntoContainer(userInput);
        if(InputCheck::isStringNumberInRange(userInput, 3))
        {
            break;
        }
        else
        {
            printw("Please enter a valid number!\n");
        }
    }
    return static_cast<PlayerOrigin>(std::stoi(userInput));
}