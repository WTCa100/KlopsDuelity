#include "./BSSP.hpp"

namespace entities::weapons::pistols
{
    BSSP::BSSP() : Weapon("British Sea Service Pistol", WEAPON_TYPE_PISTOL)
    {
        basePrice_ = 50;
        baseDmg_ = 20;
        baseAccuracy_ = 0.10;
    }
} // namespace entities::weapons::pistols
