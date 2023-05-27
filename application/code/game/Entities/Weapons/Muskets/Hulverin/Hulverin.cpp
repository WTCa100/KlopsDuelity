// Hulverin as ab. for Hand Culverin
#include "./Hulverin.hpp"

#include <ncurses.h>

namespace entities::weapons::muskets
{
    Hulverin::Hulverin() : Weapon("Hulverin", WEAPON_TYPE_MUSKET)
    {
        basePrice_ = 360;
        baseDmg_ = 50;
        baseAccuracy_ = 0.30;
    }

} // namespace entities::weapons::muskets
