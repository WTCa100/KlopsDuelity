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
    uint16_t duelCount_;
    uint32_t money_;
    uint32_t moneyWon_;
    uint16_t playerGlobalShotCount_;
    uint16_t playerGlobalShotLandedCount_;
    const Origin* pOrigin_;
    std::vector<Weapon*> weaponsOwned_; 
    void getStatsFromOrigin();
    void levelStat();

    int level_;
    int requiredExp_;
    int exp_;

    public:
    void pickWeapon() override;
    void levelUp();
    bool checkForLevelUp();
    void giveExp(int exp);
    void addWeapon(Weapon* newWeapon);
    void showFullGameStats();
    void addPlayerShotCount() { playerGlobalShotCount_++; }
    void addPlayerShotLandedCount() { playerGlobalShotLandedCount_++; }

    // Getters
    size_t getWeaponsOwnedSize() const { return weaponsOwned_.size(); }
    std::vector<Weapon*> getWeaponsOwned() const { return weaponsOwned_; }
    uint32_t getMoney() const { return money_; }
    int getLevel() const {return level_; }
    int getExp() const {return exp_; }
    int getRequiredExp() const { return requiredExp_; }
    uint16_t getDuelCount() const { return duelCount_; }
    uint32_t getMoneyWon() const { return moneyWon_; }
    uint16_t getGlobalShotCount() const {return playerGlobalShotCount_; }
    uint16_t getGlobalShotLandedCount() const { return playerGlobalShotLandedCount_; }

    // Setters
    void setMoney(const uint32_t& money) { money_ = money;}
    void setMoneyWon(const uint32_t& moneyWon) { moneyWon_ = moneyWon; }
    void setDuelCount(const uint16_t& duelCount) { duelCount_ = duelCount;}
    void setGlobalShotLandedCount(const uint16_t& shotLandedCount) { playerGlobalShotLandedCount_ = shotLandedCount; }

    Player(std::string name);
    ~Player();
};