#include "./player.hpp"

#include <ncurses.h>

// Testing leveling 
#include <ctime>

// get toolbox
#include "../../utilities/Toolbox/InputCheck/InputCheck.hpp"
// get modifiers
#include "../Modifiers/Modifiers.hpp"
// Get all weapons
#include "../Entities/Weapons/Muskets/Springfield1835/springfield1835.hpp"
#include "../Entities/Weapons/Muskets/Moukahla/moukahla.hpp"

Player::Player(std::string name) : Shooter(true, name), money_(100), pOrigin_(new Origin), level_(1), exp_(0), requiredExp_(1000), duelCount_(0), playerGlobalShotCount_(0)
{
    // Make player choose starting weapon later / weapon will be determined on origin (preferable)
    getStatsFromOrigin();   
}

void Player::giveExp(int exp)
{
    exp_ += exp;
    if(checkForLevelUp())
    {
        levelUp();
    }
    printw("Got %d exp\n", exp);
    printw("You know have %d exp\n", exp_);
    printw("Next level at: %d exp\n", requiredExp_);
}

bool Player::checkForLevelUp()
{
    if(exp_ >= requiredExp_)
    {
        return true;
    }
    return false;
}

void Player::levelUp()
{
    // increment from get go
    printw("Leveled up to %d!\n", ++level_);
    if(exp_ > requiredExp_)
    {
        exp_ = exp_ - requiredExp_;
    }

    requiredExp_ = Modifiers::calculateRequiredExp(level_, requiredExp_);
    printw("Next level at: %d exp\n", requiredExp_);
    printw("Press any key to continue...\n");
    getch();
    clear();

    // Assign additional point into stats
    levelStat();

}

void Player::pickWeapon()
{
    noecho();
    uint16_t pointedWeapon = 0;
    bool exitLoop = false;

    printw("Pick your weapon!\n");
    while(!exitLoop)
    {
        weaponsOwned_[pointedWeapon]->presentStats();
        printw("Change weapon <- previous item | next item ->\n");
        printw("Pick %s [Enter]\n", weaponsOwned_[pointedWeapon]->getWeaponName().c_str());
        uint choosenOption = getch();
        switch (choosenOption)
        {
        case KEY_ENTER:
        case      '\n':
            setCurrentlyHeldWeapon(weaponsOwned_[pointedWeapon]);
            exitLoop = true;
            break;
        case KEY_LEFT:
            if(pointedWeapon == weaponsOwned_.size() - 1)
            {
                pointedWeapon = 0;
            }
            else
            {
                ++pointedWeapon;
            }
            clear();
            break;
        case KEY_RIGHT:
            if(pointedWeapon == 0)
            {
                pointedWeapon = weaponsOwned_.size() - 1;
            }
            else
            {
                --pointedWeapon;
            }
            clear();
            break;
        default:
            printw("Please enter a valid option!\n");
            printw("Press any key to continue...\n");
            getch();
            clear();
            break;
        }
    }
    clear();

    printw("Player picked %s\n", getCurrentlyHeldWeapon()->getWeaponName().c_str());
    getch();
    echo();
}

void Player::showFullGameStats()
{
    printw("Name: %s\n", name_.c_str());
    printw("General game statistics:\n");
    printw("Duels played: %d\n", duelCount_);
    printw("Duels won: %d\n", duelsWonCount_);
    printw("Shots fired: %d\n", playerGlobalShotCount_); // TODO
    printw("Money %d\n", money_);
    printw("Money won: %d\n", moneyWon_);

    printw("Character stats:\n");
    printw("Level: %d\n", level_);
    printw("Current Exp: %d\n", exp_);
    printw("Required Exp: %d\n", requiredExp_);
    printw("Power: %d\n", power_);
    printw("Vitality: %d\n", statVitality_);
    printw("Charisma: %d\n", statCharisma_);
    printw("Aim: %d\n", statAim_);        

    printw("Weapons owned: \n");
    int iter = 0;
    for(auto weapon : weaponsOwned_)
    {
        iter ++;
        printw("%d. %s\n", iter, weapon->getWeaponName().c_str());
    }

}

void Player::levelStat()
{   
    // Disable echo
    noecho();

    int currentStat = 0;
    
    bool isStatAssigned = false;
    
    while(!isStatAssigned)
    {
        printw("What stat you would like to level up?\n");
        printw(" Use arrow keys to navigate\n");
        printw("Aim: %d", statAim_);
        if(currentStat == 0)
        {
            printw(" = > %d", statAim_ + 1);
        }
        printw("\n");
        printw("Charisma: %d", statCharisma_);
        if(currentStat == 1)
        {
            printw(" = > %d", statCharisma_ + 1);
        }
        printw("\n");
        printw("Vitality: %d", statVitality_);
        if(currentStat == 2)
        {
            printw(" = > %d", statVitality_ + 1);
        }
        printw("\n");

        int input = getch();
        switch(input)
        {
            case KEY_LEFT:
            printw("KEY LEFT PRESSED\n");
                if(currentStat == 0)
                {
                    currentStat = 2;
                    clear();
                    break;
                }
                
                currentStat--;
                clear();
                break;
            case KEY_RIGHT:
            printw("KEY RIGHT PRESSED\n");
                if(currentStat == 2)
                {
                    currentStat = 0;
                    clear();
                    break;
                }

                currentStat++;
                clear();
                break;
            case KEY_ENTER:
            case '\n':
                printw("Assigning stat to ");
                switch (currentStat)
                {
                case 0:
                    printw("aim.\n Newvalue: %d\n", statAim_ + 1);
                    break;
                
                case 1:
                    printw("charisma.\nNew value: %d\n", statCharisma_ + 1);                
                    break;
                
                case 2:
                    printw("vitality.\nNew value: %d\n", statVitality_ + 1);
                    break;
                }
                isStatAssigned = true;
                break;
            default:
                printw("NO VALID KEY PRESSED\n");
                getch();
                clear();
        }
    }

    // Enable echo
    echo();

    if(currentStat == 0)
    {
        setStatAim(statAim_ + 1);
    }
    else if(currentStat == 1)
    {
        setStatCharisma(statCharisma_ + 1);
    }
    else
    {
        setStatVit(statVitality_ + 1);
    }

}

void Player::addWeapon(Weapon* newWeapon)
{
    weaponsOwned_.push_back(newWeapon);
}

void Player::getStatsFromOrigin()
{
    this->statAim_ = pOrigin_->getBaseOriginStatAim();
    this->statCharisma_ = pOrigin_->getBaseOriginStatChraisma();
    this->statVitality_ = pOrigin_->getBaseOriginStatVitality();
    this->weaponsOwned_.push_back(pOrigin_->getBaseOriginWeapon());
    this->setCurrentlyHeldWeapon(pOrigin_->getBaseOriginWeapon());
    this->healthMax_ =  Modifiers::calculateHealth(statVitality_);
    this->health_ = healthMax_;

    evaluatePower();

}

Player::~Player()
{

    for(auto weapon : weaponsOwned_)
    {
        // The currently held weapon will be deleted later when the Shooter instance will get destroyed
        if(getCurrentlyHeldWeapon()->getWeaponName() != weapon->getWeaponName())
        {
            delete weapon;
        }
    }

    delete pOrigin_;
}

