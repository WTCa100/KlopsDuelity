// Put all math modifiers formulas in here
#include <math.h>

#include <ncurses.h>
namespace Modifiers
{

    int calculateDuelReward(const double& enemyWeaponDmg, const double& enemyWeaponAccuracy, 
                      const double& distance, const int& playerCharisma,
                      const double& baseReward)
    {
        int enemyMod = enemyWeaponDmg + (enemyWeaponAccuracy * 100);
        int distanceMod = distance * 2;
        int charismaMod = 1 + (static_cast<double>(playerCharisma) / 10);

        return (baseReward + enemyMod + distanceMod) * charismaMod;
    }

    double calculateHealth(const int& entityVitality, const double healthBase)
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

    /// @brief Calculated required exp for next level cbrt(sqrt(currentRequiredExp)) * nextLevel * 100
    /// @param nextLevel This is the next level that the player will try to reach
    /// @param currentRequiredExp default value is 1000 and stands for 1st level
    /// @return 
    int calculateRequiredExp(const int& nextLevel, const int& currentRequiredExp)
    {
        return currentRequiredExp + static_cast<int>(std::cbrt(std::pow(currentRequiredExp, 2)) + nextLevel * 100);
    }

    /// @brief Calculates the ammount of exp player needs to level up
    /// @param enemyPower enemy power always provide it's quater of value
    /// @param shotsFired devides base + power by % (capped at 10)
    /// @param distance gives 10% of it's value additionally to final exp.
    /// @param hasWon has player won (default true)
    /// @param hasEnemyDied was enemy killed during the duel
    /// @param wasOneShot was enemy killed by 1 shot (default false)
    /// @param wasTie did the duel was either tied or forfeited by the player
    /// @return 
    int calculateExpReward(int enemyPower, const double& shotsFired, const int& distance, 
                                  const bool& hasWon, const bool& hasEnemyDied,
                                  const bool& wasOneShot, const bool& wasTie)
    {
        int base = 150;
        int finalExp = base;

        // Handle shots 
        double shotsToCalc = shotsFired;
        if(shotsFired > 10)
        {
            shotsToCalc = 10;
        }
        if(shotsFired <= 0)
        {
            shotsToCalc = 1;
        }


        int powerToCalc = enemyPower;
        printw("FINAL EXP BASE: %d\n", finalExp);
        printw("FINAL EXP ENEMY QUATER: %d\n", powerToCalc / 4);
        finalExp = finalExp + (powerToCalc / 4) * ( 1.00 - (shotsToCalc / 100));
        printw("FINAL EXP HANDLE SHOT: %d\n", finalExp);
        // Handle distance
        int distanceToCalc = distance;
        int distanceVal = finalExp * static_cast<double>(distanceToCalc) / 100;
        finalExp = finalExp + distanceVal;
        printw("FINAL EXP HANDLE DISTANCE: %d\n", finalExp);        

        // Handle booleans
        if(hasWon)
        {
            int winVal = finalExp * 0.20;
            finalExp += winVal;
        }

        if(hasEnemyDied)
        {
            int enemyDownVal = finalExp * 0.10;
            if(wasOneShot)
            {
                enemyDownVal += enemyDownVal;
            }

            finalExp += enemyDownVal;
        }

        if(wasTie)
        {
            // get a fraction of 10% of normal exp value
            finalExp = finalExp * 0.10;
        }

        return finalExp;
    }

    double calculateWeaponPrice(double basePrice, int playerCharisma)
    {
        if(playerCharisma == 0)
        {
            return basePrice;
        }

        if(playerCharisma > 100)
        {
            return 1;
        }

        return basePrice -= basePrice * (static_cast<double>(playerCharisma) / 100);  

    }

} // namespace Modifiers
