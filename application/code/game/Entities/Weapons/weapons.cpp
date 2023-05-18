#include "./weapons.hpp"
#include "../../Modifiers/Modifiers.hpp"

#include <ncurses.h>
namespace entities
{
    uint32_t Weapon::wIdGlobal_ = 0;
    
    Weapon::Weapon()
    {
        wId_ = wIdGlobal_;
        wIdGlobal_++;
    }

    Weapon::Weapon(std::string wName) : name_(wName)
    {
        wId_ = wIdGlobal_;
        wIdGlobal_++; 
    }

    void Weapon::presentStats(bool isInShoop)
    {
        printw("Name: %s\n", name_.c_str());
        printw("Stast:\n");
        printw("Accuracy: %.2f\n", baseAccuracy_);
        printw("Damage: %d\n", baseDmg_);

        if(isInShoop)
        {
            printw("Pirce: %d\n", basePrice_);
        }
    }

    bool Weapon::shoot(/*List modifier*/ const double distance)
    {
        printw("**-- POW --**\n");
        int diceRoll = rand() % 99 + 1;
        return diceRoll <= Modifiers::calculateAccuracy(baseAccuracy_, distance);
    }    
    
    Weapon::~Weapon()
    {
        printw("Deleting weapon with ID %d\n", wId_);
    }    
} // namespace entities
