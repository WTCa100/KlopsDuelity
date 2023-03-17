#pragma once
namespace Modifiers
{

    extern double duelReward(const double& enemyWeaponDmg, const double& enemyWeaponAccuracy, 
                      const double& distance, const int& playerCharisma,
                      const double& baseReward = 100);

    extern double calculateHealth(const int& entityVitality, const double healthBase = 100);


} // namespace Modifiers
