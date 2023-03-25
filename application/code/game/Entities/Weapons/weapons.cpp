#include "./weapons.hpp"
#include "../../Modifiers/Modifiers.hpp"

#include <ncurses.h>
namespace entities
{
    uint32_t Weapon::wIdGlobal_ = 0;
    
    Weapon::Weapon()
    {
        printw("Creating weapon with ID: %d\n", wIdGlobal_);
        wId_ = wIdGlobal_;
        wIdGlobal_++;
    }

    Weapon::Weapon(std::string wName) : name_(wName)
    {
        printw("Creating weapon with ID: %d. Name assigned: %s\n", wIdGlobal_, name_.c_str());
        wId_ = wIdGlobal_;
        wIdGlobal_++; 
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
