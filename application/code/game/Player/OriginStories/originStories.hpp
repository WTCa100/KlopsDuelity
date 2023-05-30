#pragma once
#include <string>

#include "../../Entities/Weapons/weapons.hpp"
enum class PlayerOrigin
{
    // Dummies - change later
    kClassSoldier  = 1,
    kClassButcher  = 2,
    kClassWealthy  = 3
};

class Origin
{
    int baseOriginStatAim_;
    int baseOriginStatVitality_;
    int baseOriginStatCharisma_;
    entities::Weapon* baseOriginWeapon_;
    const PlayerOrigin startingOrigin_;
    void initStatAssign();
    PlayerOrigin choosePlayerOrigin();
    public:
    Origin();
    ~Origin() = default;

    int getBaseOriginStatAim() const { return baseOriginStatAim_;}
    int getBaseOriginStatChraisma() const { return baseOriginStatCharisma_;}
    int getBaseOriginStatVitality() const { return baseOriginStatVitality_;}
    entities::Weapon* getBaseOriginWeapon() const { return baseOriginWeapon_; }

};

