#pragma once

#include <iostream>
#include <vector>

// Get all types of entities
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
    Player* mainCharacter_;
    public:
    void characterCreation();
    void duel();
    Session(/*pass config*/);
    ~Session();
};