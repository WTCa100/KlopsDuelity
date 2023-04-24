#pragma once

#include <iostream>
#include <vector>

#include "./Duel/duels.hpp"
// Abstact
#include "../Entities/HEU/heu.hpp"
// HEUs
#include "../Entities/HEU/Shooter/shooter.hpp"
#include "../Player/player.hpp"

// Menus
#include "../Display/Menu/SessionMainScreen/SessionMainScreen.hpp"

enum class oponentDifficulty{
    kEasy      = 1,
    kMediocore = 2,
    kHard      = 3
};

class Session
{
    private:
    // Config
    // Store information about every weapon/heu
    std::vector<entities::HEU*> heuCount_;
    Duel* fighting_;
    Player* mainCharacter_;

    public:
    entities::HEUTypes::Shooter* pickOponent();
    entities::HEUTypes::Shooter* generateOponent(oponentDifficulty difLvl);
    void cabin();
    void core();
    void characterCreation();
    void shop();
    void duel();
    Session(/*pass config*/);
    ~Session();
};