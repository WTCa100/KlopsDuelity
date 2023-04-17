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

    int level_;
    int requiredExp_;
    int exp_;

    public:
    void levelUp();
    bool checkForLevelUp();
    void giveExp(int exp);
    void addWeapon(Weapon* newWeapon);

    // Getters
    size_t getWeaponsOwnedSize() const { return weaponsOwned_.size(); }
    std::vector<Weapon*> getWeaponsOwned() const { return weaponsOwned_; }
    double getMoney() const { return money_; }
    int getLevel() const {return level_; }
    int getExp() const {return exp_; }
    int getRequiredExp() const { return requiredExp_; }

    // Setters
    void setMoney(const double& money) { money_ = money;}

    Player(std::string name);
    ~Player();
};