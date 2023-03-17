#pragma once

#include <iostream>
#include <string>

#include "../Entities/HEU/heu.hpp"
#include "../Entities/HEU/Shooter/shooter.hpp"

// Get player origins
#include "./OriginStories/originStories.hpp"

using entities::HEUTypes::Shooter;
using entities::HEU;

class Player : public Shooter 
{
    private:
    double money_;
    const Origin* pOrigin_;

    void getStatsFromOrigin();

    public:
    Player(std::string name);
    ~Player();
};