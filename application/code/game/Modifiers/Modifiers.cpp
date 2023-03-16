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


} // namespace Modifiers
