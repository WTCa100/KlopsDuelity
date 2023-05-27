#include "./HarpersFerry1805.hpp"

namespace entities::weapons::pistols
{
    HarpersFerry1805::HarpersFerry1805() : Weapon("Harpers Ferry M.1805", WEAPON_TYPE_PISTOL)
    {
        basePrice_ = 35;
        baseDmg_ = 24;
        baseAccuracy_ = 0.09;
    }
} // namespace entities::weapons::pistols
