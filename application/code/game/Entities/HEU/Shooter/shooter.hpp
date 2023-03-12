#pragma once
#include<iostream>
#include<string>

#include "../heu.hpp"

// Import all weapons
#include "../../Weapons/weapons.hpp"
#include "../../Weapons/Muskets/Springfield1835/springfield1835.hpp"

namespace entities::HEUTypes
{
    class Shooter : public HEU
    {
        private:
        Weapon* currentlyHeldWeapon_;
        public:
        void presentWeapon();
        Shooter();
        ~Shooter();
    };
    
} // namespace entities