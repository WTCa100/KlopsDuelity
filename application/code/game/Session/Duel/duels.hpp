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

const uint DUEL_MIN_DIST = 4;
const uint DUEL_MAX_DIST = 95;
const uint DUEL_MAX_ROUND = 20;

class Duel
{
friend class entities::HEU;
private:
    uint32_t reward_;
    int expReward_;
    int duelShotCount_;
    int roundCount_;
    bool isCutShort_;

    double playerStartingHp_;
    double enemyStartingHp_;
    double enemyDmgDealt_;
    double playerDmgDealt_;

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
    bool askForSurrender();  

    bool getIsCutShort() const { return isCutShort_; }

    Duel(Player* player, Shooter* oponent);
    ~Duel();
};