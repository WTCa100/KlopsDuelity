#include "./Enfield1861.hpp"

#include <ncurses.h>

namespace entities::weapons::muskets
{
    Enfield1861::Enfield1861() : Weapon("Enfield model 1861", WEAPON_TYPE_MUSKET)
    {
        basePrice_ = 250;
        baseDmg_ = 40;
        baseAccuracy_ = 0.28;
    }

    Enfield1861::~Enfield1861() = default;
} // namespace entities::weapons::muskets
