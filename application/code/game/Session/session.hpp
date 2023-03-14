#pragma once

#include <iostream>
#include <vector>

#include "./Duel/duels.hpp"
// Abstact
#include "../Entities/HEU/heu.hpp"
// HEUs
#include "../Entities/HEU/Shooter/shooter.hpp"
#include "../Player/player.hpp"


class Session
{
    private:
    // Config
    // Store information about every weapon/heu
    std::vector<entities::HEU*> heuCount_;
    Duel* fighting_;
    Player* mainCharacter_;
    public:
    void characterCreation();
    void duel();
    Session(/*pass config*/);
    ~Session();
};