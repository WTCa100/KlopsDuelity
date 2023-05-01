#include "./session.hpp"

#include <ctime>
#include <algorithm>
// Get ncruses
#include <ncurses.h>
#include "../../utilities/IOStream/NIO.hpp"
// Toolbox
#include "../../utilities/Toolbox/InputCheck/InputCheck.hpp"
// Entities
#include "../Entities/HEU/Shopkeeper/shopkeeper.hpp"
// Weapons
#include "../Entities/Weapons/weapons.hpp"
#include "../Entities/Weapons/Muskets/Moukahla/moukahla.hpp"
#include "../Entities/Weapons/Muskets/Springfield1835/springfield1835.hpp"


Session::Session(FManager* fMgr ) : mainCharacter_(nullptr), fighting_(nullptr), heuCount_(), fMgr_(fMgr)
{
    save_ = new gameSave(fMgr_);
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
    delete save_;
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
    heuCount_.push_back(mainCharacter_);
}

void Session::shop()
{
    entities::HEUTypes::Shopkeeper* shopOwner = new entities::HEUTypes::Shopkeeper(mainCharacter_);
    shopOwner->act();
    delete shopOwner;
}

void Session::cabin()
{
    noecho();
    if(mainCharacter_)
    {
        while(true)
        {
            mainCharacter_->showFullGameStats();            
            printw("Press 'q' to exit\n");
            if(getch() == 'q')
            {
                break;
            }
            else
            {
                clear();
            }            
        }
    }

    clear();
    echo();
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
        case SessionMainScreenOptions::kGoToShop:
            shop();        
            break;
        case SessionMainScreenOptions::kGoToCabin:
            cabin();
            break;
        case SessionMainScreenOptions::kQuit :
            gameOn = false;
            break;
        }
    }

    delete mainSessionDisplay;
}

entities::HEUTypes::Shooter* Session::generateOponent(oponentDifficulty difLvl)
{
    entities::HEUTypes::Shooter* returnOponent = new entities::HEUTypes::Shooter(false, "");
    // Reference on player power will be based on his best weapon
    int powerRefferencePoint = mainCharacter_->getPower();

    // Initialize all possible weapons and allocate them
    std::vector<entities::Weapon*> weaponChoices = 
    { new entities::weapons::muskets::Springfield1835,
      new entities::weapons::muskets::Moukahla};
    // To keep track which delete later, we will store information which weapon was choosen
    size_t pickedWeapon = 0;

    // If player stats are only zero-s then return dummy 0/0/0
    if(mainCharacter_->getStatAim() == 0 && mainCharacter_->getStatCharisma() == 0 && mainCharacter_->getStatVit() == 0)
    {
        returnOponent->setStatAim(0);
        returnOponent->setStatCharisma(0);
        returnOponent->setStatVit(0);

        return returnOponent;
    }

    // Get player maximum stat value
    std::vector<int> refStats{mainCharacter_->getStatAim(), mainCharacter_->getStatCharisma(), mainCharacter_->getStatVit()};
    int refMaxStat = *std::max_element(refStats.begin(), refStats.end());

    switch (difLvl)
    {
    case oponentDifficulty::kEasy:
        // ATM name is changed for possible debug purposes
        returnOponent->setEntityName("ShooterEasy");
        // Assign stats depending on player stats
        // Easy shall generate power of 65 to 80% of Players
        do
        {   
            returnOponent->setStatAim(rand() % refMaxStat * 0.65 + rand() % refMaxStat);
            returnOponent->setStatCharisma(rand() % refMaxStat * 0.65 + rand() % refMaxStat);
            returnOponent->setStatVit(rand() % refMaxStat * 0.65 + rand() % refMaxStat);
            pickedWeapon = rand() % weaponChoices.size();
            returnOponent->setCurrentlyHeldWeapon( weaponChoices[pickedWeapon] );
        } while (returnOponent->getPower() > (powerRefferencePoint * 0.8) || returnOponent->getPower() < (powerRefferencePoint * 0.65));
        
        break;
    case oponentDifficulty::kMediocore:
        returnOponent->setEntityName("ShooterMediocore");
        // Assign stats depending on player stats
        // Mediocore shall generate power of 80 to 120% of Players
        do
        {   
            returnOponent->setStatAim(rand() % refMaxStat * 0.80 + rand() % refMaxStat * 1.20);
            returnOponent->setStatCharisma(rand() % refMaxStat * 0.80 + rand() % refMaxStat * 1.20);
            returnOponent->setStatVit(rand() % refMaxStat * 0.80 + rand() % refMaxStat * 1.20);
            pickedWeapon = rand() % weaponChoices.size();
            returnOponent->setCurrentlyHeldWeapon( weaponChoices[pickedWeapon] );
        } while (returnOponent->getPower() > (powerRefferencePoint * 1.20) || returnOponent->getPower() < (powerRefferencePoint * 0.80));
         
        break;
    case oponentDifficulty::kHard:
        returnOponent->setEntityName("ShooterHard");
        // Assign stats depending on player stats
        // Mediocore shall generate power of 120 to 250% of Players        
        do
        {   
            returnOponent->setStatAim(rand() % refMaxStat * 1.20 + rand() % refMaxStat * 2.50);
            returnOponent->setStatCharisma(rand() % refMaxStat * 1.20 + rand() % refMaxStat * 2.50);
            returnOponent->setStatVit(rand() % refMaxStat * 1.20 + rand() % refMaxStat * 2.50);
            pickedWeapon = rand() % weaponChoices.size();
            returnOponent->setCurrentlyHeldWeapon( weaponChoices[pickedWeapon] );
        } while (returnOponent->getPower() > (powerRefferencePoint * 2.50) || returnOponent->getPower() < (powerRefferencePoint * 1.20));
         

        break;
    default:
        break;
    }

    for(int weaponId = 0; weaponId < weaponChoices.size(); weaponId++)
    {
        if(weaponId != pickedWeapon)
        {
            delete weaponChoices[weaponId];
        }
    }

    return returnOponent;
}

entities::HEUTypes::Shooter* Session::pickOponent()
{
    std::vector<entities::HEUTypes::Shooter*> listOfVilains(3, nullptr);
    // Generate 3 oponents based on player stats
    listOfVilains[0] = generateOponent(oponentDifficulty::kEasy);
    listOfVilains[1] = generateOponent(oponentDifficulty::kMediocore);
    listOfVilains[2] = generateOponent(oponentDifficulty::kHard);
    std::string choosenOponent; 
    while(true)
    {
        clear();
        printw("Pick your oponent!\n");
        for(int enemyId = 0; enemyId < listOfVilains.size(); enemyId++)
        {
            printw("Oponent #%i\n", enemyId + 1);
            printw("Name: %s\n", listOfVilains[enemyId]->getEntityName().c_str());
            printw("Weapon: %s\n", listOfVilains[enemyId]->getCurrentlyHeldWeapon()->getWeaponName().c_str());
            printw("Power: %d\n", listOfVilains[enemyId]->getPower());
            printw("(Vit: %d, Chr: %d, Aim: %d)\n\n",
                    listOfVilains[enemyId]->getStatVit(), listOfVilains[enemyId]->getStatCharisma(),
                    listOfVilains[enemyId]->getStatAim());
        }
        printw("Your option: ");
        InputCheck::helperInsertInputIntoContainer(choosenOponent);

        printw("Picked: %s\n", choosenOponent.c_str());
        getch();
        if(InputCheck::isStringNumberInRange(choosenOponent, 3))
        {
            break;
        }
        else
        {
            printw("Please enter valid option!\n");
            printw("Press any key to continue...\n");
            getch();
        }
    }

    for(int enemyId = 0; enemyId < listOfVilains.size(); enemyId++)
    {
        if(enemyId != std::stoi(choosenOponent) - 1)
        {
            delete listOfVilains[enemyId];
        }
    }

    return listOfVilains[std::stoi(choosenOponent) - 1];
}

void Session::duel()
{
    printw("!-- Debug prepare variables for duel\n");
    entities::HEUTypes::Shooter* enemy = pickOponent();
    heuCount_.push_back(enemy);
    fighting_ = new Duel(mainCharacter_, enemy);
    fighting_->prepareForFight();
    fighting_->shootOut();
    delete fighting_;
    // After game show health of the oponents
    printw("!-- Debug player character health: %.2f\n", mainCharacter_->getHealth());
    printw("!-- Debug Enemy character health: %.2f\n", enemy->getHealth());
}