#include "./weapons.hpp"
#include "../../Modifiers/Modifiers.hpp"

#include <ncurses.h>
namespace entities
{
    uint32_t Weapon::wIdGlobal_ = 0;
    
    Weapon::Weapon() : type_("UNDEFINED")
    {
        wId_ = wIdGlobal_;
        wIdGlobal_++;
    }

    Weapon::Weapon(std::string wName, std::string wType) : name_(wName), type_(wType)
    {
        wId_ = wIdGlobal_;
        wIdGlobal_++; 
    }

    void Weapon::presentStats(bool isInShoop, int playerCharisma)
    {
        printw("Name: %s\n", name_.c_str());
        printw("Type: %s\n", type_.c_str());
        printw("Weapon Stats:\n");
        printw("Accuracy: %.2f\n", baseAccuracy_);
        printw("Damage: %.0f\n", baseDmg_);

        if(isInShoop)
        {
            printw("Pirce: %.2f\n", Modifiers::calculateWeaponPrice(basePrice_, playerCharisma));
        }
    }

    double Weapon::getWeaponModPrice(const int& playerCharisma)
    {
        return Modifiers::calculateWeaponPrice(basePrice_, playerCharisma);
    }

    bool Weapon::shoot(/*List modifier*/ const double distance)
    {
        printw("**-- POW --**\n");
        int diceRoll = rand() % 99 + 1;
        return diceRoll <= Modifiers::calculateAccuracy(baseAccuracy_, distance);
    }    
    
    Weapon::~Weapon() {}
} // namespace entities
