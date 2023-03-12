#pragma once
#include <iostream>

#include "../heu.hpp"
#include "../../weaponry/muskets/Springfield1835/springfield1835.hpp"

namespace entity
{
    class shooter
    {
    protected:
        std::string name_;
        // Weapons
        // Currently eq. weapon
        Weapon* heldWeapon_;
        // Honor
        // Money
        // Name
    public:
        shooter(/* args */);
        void showWeapon();
        shooter(bool isPlayer);
        ~shooter();
    };
};

