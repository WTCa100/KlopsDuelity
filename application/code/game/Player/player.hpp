#pragma once

#include<iostream>

#include "../Entities/HEU/heu.hpp"
#include "../Entities/HEU/Shooter/shooter.hpp"

using entities::HEUTypes::Shooter;
using entities::HEU;

class Player : public Shooter 
{
    private:
    double money_;

    public:
    Player(std::string name);
    ~Player();
};