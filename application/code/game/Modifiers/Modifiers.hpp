#pragma once
namespace Modifiers
{

    extern int calculateDuelReward(const double& enemyWeaponDmg, const double& enemyWeaponAccuracy, 
                          const double& distance, const int& playerCharisma,
                          const double& baseReward = 100);

    extern double calculateHealth(const int& entityVitality, const double healthBase = 100);

    extern double calculateAccuracy(const double& baseAccuracy, const double& distance);

    extern int calculateEntityPower(const int& entityAim, const int& entityVitality, const int& entityCharisma);
    
    extern int calculateWeaponPower(const double& weaponBaseAccuracy = 0.0, const double& weaponBaseDamage = 0.0);

    extern int calculateRequiredExp(const int& nextLevel, const int& requiredExp);

    extern int calculateExpReward(int enemyPower, const double& shotsFired, const int& distance, 
                                  const bool& hasWon = true, const bool& hasEnemyDied = false,
                                  const bool& wasOneShot = false, const bool& wasTie = false,
                                  const bool& wasCutShort = false);
    extern double calculateWeaponPrice(double basePrice, int playerCharisma);

} // namespace Modifiers
