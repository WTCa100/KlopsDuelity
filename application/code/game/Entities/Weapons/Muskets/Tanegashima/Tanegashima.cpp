#include "./Tanegashima.hpp"

#include <ncurses.h>

namespace entities::weapons::muskets
{
    Tanegashima::Tanegashima() : Weapon("Tanegashima", WEAPON_TYPE_MUSKET)
    {
        basePrice_ = 135;
        baseDmg_ = 45;
        baseAccuracy_ = 0.17;
    }
} // namespace entities::weapons::muskets
