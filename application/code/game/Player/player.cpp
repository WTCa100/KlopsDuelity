#include "./player.hpp"

#include <ncurses.h>

// get toolbox
#include "../../utilities/Toolbox/InputCheck/InputCheck.hpp"
// get modifiers
#include "../Modifiers/Modifiers.hpp"

#include "../Entities/Weapons/Muskets/Springfield1835/springfield1835.hpp"

Player::Player(std::string name) : Shooter(true, name), money_(100), pOrigin_(new Origin)
{
    // Make player choose starting weapon later / weapon will be determined on origin (preferable)
    weaponsOwned_.push_back(new entities::weapons::muskets::springfield1835);
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

    this->healthMax_ =  Modifiers::calculateHealth(statVitality_);
    this->health_ = healthMax_;
}

Player::~Player()
{
    printw("Player despawned\n");
    for(auto weapon : weaponsOwned_)
    {
        delete weapon;
    }
}

