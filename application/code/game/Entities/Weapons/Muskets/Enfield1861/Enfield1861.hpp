#pragma once

#include <iostream>

#include "../../weapons.hpp"

namespace entities::weapons::muskets
{
    class Enfield1861 : public Weapon
    {
    public:
        Enfield1861();
        ~Enfield1861();
    };
    
} // namespace entities::weapons::muskets
