#include "./BSSP.hpp"

namespace entities::weapons::pistols
{
    BSSP::BSSP() : Weapon("British Sea Service Pistol", WEAPON_TYPE_PISTOL)
    {
        basePrice_ = 30;
        baseDmg_ = 20;
        baseAccuracy_ = 10;
    }
} // namespace entities::weapons::pistols
