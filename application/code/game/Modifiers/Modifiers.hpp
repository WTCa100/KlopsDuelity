#pragma once
namespace Modifiers
{

    extern double duelReward(const double& enemyWeaponDmg, const double& enemyWeaponAccuracy, 
                      const double& distance, const int& playerCharisma,
                      const double& baseReward = 100);

    extern double calculateHealth(const int& entityVitality, const double healthBase = 100);

    extern double calculateAccuracy(const double& baseAccuracy, const double& distance);

    extern int calculateEntityPower(const int& entityAim, const int& entityVitality, const int& entityCharisma);
    
    extern int calculateWeaponPower(const double& weaponBaseAccuracy = 0.0, const double& weaponBaseDamage = 0.0);

} // namespace Modifiers
