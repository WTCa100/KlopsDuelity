#include <string>
#include <ncurses.h>

#include "./originStories.hpp"

// Get toolbox
#include "../../../utilities/Toolbox/InputCheck/InputCheck.hpp"

// Get all weapons
#include "../../Entities/Weapons/Muskets/Moukahla/moukahla.hpp"
#include "../../Entities/Weapons/Muskets/Springfield1835/springfield1835.hpp"

Origin::Origin() : startingOrigin_(choosePlayerOrigin())
{
    initStatAssign();
}

void Origin::initStatAssign()
{

    switch (startingOrigin_)
    {
    case PlayerOrigin::kClassSoldier:
        baseOriginStatAim_ = 3;
        baseOriginStatCharisma_ = 1;
        baseOriginStatVitality_ = 1;
        baseOriginWeapon_ = new entities::weapons::muskets::Moukahla();
        break;
    case PlayerOrigin::kClassWealthy:
        baseOriginStatAim_ = 1;
        baseOriginStatCharisma_ = 3;
        baseOriginStatVitality_ = 1;
        baseOriginWeapon_ = new entities::weapons::muskets::Moukahla();
        break;
    case PlayerOrigin::kClassButcher:
        baseOriginStatAim_ = 1;
        baseOriginStatCharisma_ = 1;
        baseOriginStatVitality_ = 3;
        baseOriginWeapon_ = new entities::weapons::muskets::Springfield1835();
        break;
    default:
        printw("Cannot find specified origin - assigning default values\n");
        baseOriginStatAim_ = 0;
        baseOriginStatCharisma_ = 0;
        baseOriginStatVitality_ = 0;
        baseOriginWeapon_ = new entities::weapons::muskets::Springfield1835();
        break;
    }

}

PlayerOrigin Origin::choosePlayerOrigin()
{
    std::string userInput("");
    // Later we will make stories now we will only operate on debug values
    while(true)
    {
        printw("What is thy story!\n");
        printw("1 I was born into a family of warriors, where every member was and forever will be a soldier!\n");
        printw("2 We were a poor family, my father was a butcher and I tend to help him here and there.\n");
        printw("3 My family is known in the entire continent, we are rich and powerful!\n");
        InputCheck::helperInsertInputIntoContainer(userInput);
        if(InputCheck::isStringNumberInRange(userInput, 3))
        {
            break;
        }
        else
        {
            printw("Please enter a valid number!\n");
            printw("Press any key to continue...\n");
            getch();
        }
        clear();
    }
    clear();
    return static_cast<PlayerOrigin>(std::stoi(userInput));
}