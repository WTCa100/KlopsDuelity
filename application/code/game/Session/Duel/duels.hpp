#pragma once

#include <iostream>
#include <vector>
#include <string>

// Get abstraction
#include "../../Entities/HEU/heu.hpp"
#include "../../Entities/Weapons/weapons.hpp"
#include "../../Entities/Weapons/Muskets/Springfield1835/springfield1835.hpp"
// Get concrete classes
#include "../../Entities/HEU/Shooter/shooter.hpp"
#include "../../Player/player.hpp"

class Duel
{
private:
    Player* player_;
    Shooter* oponent_;
    Shooter* winner_;
public:
    void prepareForFight();
    Shooter* shootOut();
    void announceWinner();
    Duel(Player* player, Shooter* oponent);
    ~Duel();
};