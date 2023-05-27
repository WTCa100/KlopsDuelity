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
#include "../Entities/HEU/Shooter/Names/Names.hpp"
// Weapons
#include "../Entities/Weapons/Muskets/Moukahla/moukahla.hpp"
#include "../Entities/Weapons/Muskets/Springfield1835/springfield1835.hpp"
#include "../Entities/Weapons/Muskets/Enfield1861/Enfield1861.hpp"
#include "../Entities/Weapons/Muskets/Hulverin/Hulverin.hpp"
#include "../Entities/Weapons/Muskets/Tanegashima/Tanegashima.hpp"
#include "../Entities/Weapons/Pistols/BSSP/BSSP.hpp"
#include "../Entities/Weapons/Pistols/HarpersFerry1805/HarpersFerry1805.hpp"

Session::Session() : mainCharacter_(nullptr), fighting_(nullptr), heuCount_()
{
    clear();
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

        // Check if player died and display game over
        if(mainCharacter_->getIsDeadStatus())
        {
            printw("Game over!\n");
            getch();
        }

    }

    delete mainSessionDisplay;
}

std::vector<entities::Weapon*> Session::excludeWeaponTypeFromVector(const std::vector<entities::Weapon*>& targetVec, 
                                                                    std::set<std::string> excludeTypes)
{
    std::vector <entities::Weapon*> modifiedVector;
    // Handle empty set
    if(excludeTypes.empty())
    {
        return targetVec;
    }

    for(auto excludedType : excludeTypes)
    {
        for(auto weaponInVec : targetVec)
        {
            if(weaponInVec->getWeaponType() != excludedType)
            {
                modifiedVector.push_back(weaponInVec);
            }
        }
    }

    return modifiedVector;

}


entities::HEUTypes::Shooter* Session::generateOponent(oponentDifficulty difLvl)
{
    entities::HEUTypes::Shooter* returnOponent = new entities::HEUTypes::Shooter(false, "");
    // Reference on player power will be based on his best weapon
    int powerRefferencePoint = mainCharacter_->getPower();

    // Initialize all possible weapons and allocate them
    std::vector<entities::Weapon*> weaponChoices = 
    { new entities::weapons::muskets::Springfield1835,
      new entities::weapons::muskets::Moukahla,
      new entities::weapons::muskets::Hulverin,
      new entities::weapons::muskets::Tanegashima,
      new entities::weapons::muskets::Enfield1861,
      new entities::weapons::pistols::BSSP,
      new entities::weapons::pistols::HarpersFerry1805};
    // To keep track which delete later, we will store information which weapon was choosen
    size_t pickedWeapon = 0;

    std::vector<entities::Weapon*> nonEasyWeaponChoices = excludeWeaponTypeFromVector(weaponChoices, {WEAPON_TYPE_PISTOL});

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

    std::string generatedName = entities::Names::tableOfNames[rand() % entities::Names::tableOfNames.size()] + " " + entities::Names::tableOfSurnames[rand() % entities::Names::tableOfSurnames.size()];


    switch (difLvl)
    {
    case oponentDifficulty::kEasy:
        // ATM name is changed for possible debug purposes
        returnOponent->setEntityName(generatedName);
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
        returnOponent->setEntityName(generatedName);
        // Assign stats depending on player stats
        // Mediocore shall generate power of 80 to 120% of Players
        do
        {   
            returnOponent->setStatAim(rand() % refMaxStat * 0.80 + rand() % refMaxStat * 1.20);
            returnOponent->setStatCharisma(rand() % refMaxStat * 0.80 + rand() % refMaxStat * 1.20);
            returnOponent->setStatVit(rand() % refMaxStat * 0.80 + rand() % refMaxStat * 1.20);
            pickedWeapon = rand() % nonEasyWeaponChoices.size();
            returnOponent->setCurrentlyHeldWeapon( weaponChoices[pickedWeapon] );
        } while (returnOponent->getPower() > (powerRefferencePoint * 1.20) || returnOponent->getPower() < (powerRefferencePoint * 0.80));
         
        break;
    case oponentDifficulty::kHard:
        returnOponent->setEntityName(generatedName);
        // Assign stats depending on player stats
        // Mediocore shall generate power of 120 to 250% of Players        
        do
        {   
            returnOponent->setStatAim(rand() % refMaxStat * 1.20 + rand() % refMaxStat * 2.50);
            returnOponent->setStatCharisma(rand() % refMaxStat * 1.20 + rand() % refMaxStat * 2.50);
            returnOponent->setStatVit(rand() % refMaxStat * 1.20 + rand() % refMaxStat * 2.50);
            pickedWeapon = rand() % nonEasyWeaponChoices.size();
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
    std::string choosenOption; 
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
        printw("Type 'quit' to exit\n");
        printw("Your option: ");
        InputCheck::helperInsertInputIntoContainer(choosenOption);

        clear();
        if(InputCheck::isStringNumberInRange(choosenOption, 3))
        {
            break;
        }
        else if(InputCheck::helperStringToLower(choosenOption) == "quit" || tolower(choosenOption[0]) == 'q' )
        {
            for(auto heu : listOfVilains)
            {
                if(heu) delete heu;
            }
            return nullptr;
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
        if(enemyId != std::stoi(choosenOption) - 1)
        {
            delete listOfVilains[enemyId];
        }
    }

    return listOfVilains[std::stoi(choosenOption) - 1];
}

void Session::duel()
{
    entities::HEUTypes::Shooter* enemy = pickOponent();
    if(enemy)
    {
        heuCount_.push_back(enemy);
        fighting_ = new Duel(mainCharacter_, enemy);
        fighting_->prepareForFight();
        fighting_->shootOut();
        delete fighting_;
    }
}