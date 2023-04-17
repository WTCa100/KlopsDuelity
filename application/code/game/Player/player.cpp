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

Player::Player(std::string name) : Shooter(true, name), money_(100), pOrigin_(new Origin), level_(1), exp_(0), requiredExp_(1000)
{
    // Make player choose starting weapon later / weapon will be determined on origin (preferable)
    getStatsFromOrigin();   
    printw("Player created!\n");
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
    getch();
    for(auto weapon : weaponsOwned_)
    {
        getch();
        // The currently held weapon will be deleted later when the Shooter instance will get destroyed
        if(getCurrentlyHeldWeapon()->getWeaponName() != weapon->getWeaponName())
        {
            delete weapon;
        }
    }

    delete pOrigin_;
}

