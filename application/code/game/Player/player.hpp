#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../Entities/HEU/heu.hpp"
#include "../Entities/HEU/Shooter/shooter.hpp"

// Get player origins
#include "./OriginStories/originStories.hpp"

using entities::HEUTypes::Shooter;
using entities::HEU;
using entities::Weapon;

class Player : public Shooter 
{
    private:
    double money_;
    const Origin* pOrigin_;
    std::vector<Weapon*> weaponsOwned_; 
    void getStatsFromOrigin();
    public:
    size_t getWeaponsOwnedSize() const { return weaponsOwned_.size(); }
    std::vector<Weapon*> getWeaponsOwned() const { return weaponsOwned_; }
    void addWeapon(Weapon* newWeapon);
    double getMoney() const { return money_; }

    void setMoney(const double& money) { money_ = money;}

    Player(std::string name);
    ~Player();
};