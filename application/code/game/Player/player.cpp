#include "./player.hpp"

#include <ncurses.h>

// get toolbox
#include "../../utilities/Toolbox/InputCheck/InputCheck.hpp"
// get modifiers
#include "../Modifiers/Modifiers.hpp"
// Get all weapons
#include "../Entities/Weapons/Muskets/Springfield1835/springfield1835.hpp"
#include "../Entities/Weapons/Muskets/Moukahla/moukahla.hpp"

Player::Player(std::string name) : Shooter(true, name), money_(100), pOrigin_(new Origin)
{
    // Make player choose starting weapon later / weapon will be determined on origin (preferable)
    getStatsFromOrigin();   
    printw("Player created!\n");
}

void Player::addWeapon(Weapon* newWeapon)
{
    weaponsOwned_.push_back(newWeapon);
}

void Player::getStatsFromOrigin()
{
    printw("Assign stats to %s\n", this->name_.c_str());
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
    printw("Player despawned\n");
    printw("segFault Fix#4\n");
    printw("Size: %d\n", weaponsOwned_.size());
    getch();
    for(auto weapon : weaponsOwned_)
    {
        printw("GETTING INTO WEAPONRY segFaultFix#5\n");
        printw("NAME: %s", weapon->getWeaponName().c_str());
        getch();
        // The currently held weapon will be deleted later when the Shooter instance will get destroyed
        if(getCurrentlyHeldWeapon()->getWeaponName() != weapon->getWeaponName())
        {
            delete weapon;
        }
    }

    delete pOrigin_;
}

