#pragma once

#include <iostream>
#include <vector>

#include "./Duel/duels.hpp"
// Abstact
#include "../Entities/HEU/heu.hpp"
// HEUs
#include "../Entities/HEU/Shooter/shooter.hpp"
#include "../Player/player.hpp"

// Toolbox
#include "../../utilities/Toolbox/FileManager/Fmanager.hpp"

// Saving
#include "./Gamestate/gameSave.hpp"

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
    // Store information about every heu
    gameSave* save_;
    std::vector<entities::HEU*> heuCount_;
    Duel* fighting_;
    Player* mainCharacter_;
    FManager* fMgr_;
    public:
    entities::HEUTypes::Shooter* pickOponent();
    entities::HEUTypes::Shooter* generateOponent(oponentDifficulty difLvl);
    void cabin();
    void core();
    void characterCreation();
    void shop();
    void duel();

    // Ctor/Dtor
    Session(FManager* fMgr/*pass config*/);
    ~Session();
};