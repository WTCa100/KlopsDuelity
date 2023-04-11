// Put all math modifiers formulas in here

namespace Modifiers
{

    double duelReward(const double& enemyWeaponDmg, const double& enemyWeaponAccuracy, 
                      const double& distance, const int& playerCharisma,
                      const double& baseReward = 100)
    {
        double enemyMod = enemyWeaponDmg + enemyWeaponAccuracy * 100;
        double distanceMod = distance * 2;
        double charismaMod = 1 + (static_cast<double>(playerCharisma) / 10);

        return (baseReward + enemyMod + distanceMod) * charismaMod;
    }

    double calculateHealth(const int& entityVitality, const double healthBase = 100)
    {
        return healthBase * (1 + (static_cast<double>(entityVitality) / 10));
    }

    double calculateAccuracy(const double& baseAccuracy, const double& distance)
    {
        return (baseAccuracy * 10) * (100 / distance);
    }

    int calculateEntityPower(const int& entityAim, const int& entityVitality, const int& entityCharisma)
    {
        return entityAim * 100 + entityVitality * 36 + entityCharisma * 12;
    }

    int calculateWeaponPower(const double& weaponBaseAccuracy = 0.0, const double& weaponBaseDamage = 0.0)
    {
        return weaponBaseAccuracy * 5 + weaponBaseDamage * 5;
    }

} // namespace Modifiers
