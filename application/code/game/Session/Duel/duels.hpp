#pragma once

#include <iostream>
#include <vector>
#include <string>

// Get abstraction
#include "../../Entities/HEU/heu.hpp"
#include "../../Entities/Weapons/weapons.hpp"
// Get concrete classes
#include "../../Entities/HEU/Shooter/shooter.hpp"
#include "../../Player/player.hpp"

class Duel
{
friend class entities::HEU;
private:
    uint32_t reward_;
    int expReward_;
    int duelShotCount_;
    Player* player_;
    Shooter* oponent_;
    Shooter* winner_;
    /// @brief Affects weapon dmg and accuracy as well as possible reward
    double distance_;
    void changeDistance();
    void calculateReward();
    
public:
    void prepareForFight();
    Shooter* shootOut();
    void announceWinner();
    Duel(Player* player, Shooter* oponent);
    ~Duel();
};