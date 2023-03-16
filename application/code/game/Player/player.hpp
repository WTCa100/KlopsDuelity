#pragma once

#include <iostream>
#include <string>

#include "../Entities/HEU/heu.hpp"
#include "../Entities/HEU/Shooter/shooter.hpp"

using entities::HEUTypes::Shooter;
using entities::HEU;

enum class PlayerOrigin
{
    // Dummies - change later
    kBasicAim = 1,
    kBasicVitality = 2,
    kBasicCharisma = 3
};

class Player : public Shooter 
{
    private:
    double money_;
    const PlayerOrigin pOrigin_;
    void initStatEvaluation();

    public:
    Player(std::string name);
    static PlayerOrigin choosePlayerOrigin();
    ~Player();
};