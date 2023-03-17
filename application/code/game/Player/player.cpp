#include "./player.hpp"

// get toolbox
#include "../../utilities/Toolbox/InputCheck/InputCheck.hpp"
// get modifiers
#include "../Modifiers/Modifiers.hpp"

Player::Player(std::string name) : Shooter(true, name), money_(100), pOrigin_(new Origin)
{
    getStatsFromOrigin();
    std::cout << "Player created\n";
}

void Player::getStatsFromOrigin()
{
    std::cout << "Assigning stats to: " << name_ << std::endl; 
    this->statAim_ = pOrigin_->getBaseOriginStatAim();
    this->statCharisma_ = pOrigin_->getBaseOriginStatChraisma();
    this->statVitality_ = pOrigin_->getBaseOriginStatVitality();

    this->healthMax_ =  Modifiers::calculateHealth(statVitality_);
    this->health_ = healthMax_;
}

Player::~Player()
{
    std::cout << "Player despawned\n";
}

