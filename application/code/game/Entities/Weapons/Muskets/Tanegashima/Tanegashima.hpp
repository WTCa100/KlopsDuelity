#pragma once

#include <iostream>

#include "../../weapons.hpp"

namespace entities::weapons::muskets
{
    class Tanegashima : public Weapon
    {
        public:
        Tanegashima();
        ~Tanegashima() = default;
    };

} // namespace entities::weapons::muskets
