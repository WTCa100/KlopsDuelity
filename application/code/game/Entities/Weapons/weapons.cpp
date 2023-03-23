#include "./weapons.hpp"
#include "../../Modifiers/Modifiers.hpp"
namespace entities
{
    uint32_t Weapon::wIdGlobal_ = 0;
    
    Weapon::Weapon()
    {
        std::cout << "Creating weapon with ID: " << wIdGlobal_ << std::endl;
        wId_ = wIdGlobal_;
        wIdGlobal_++;
    }

    Weapon::Weapon(std::string wName) : name_(wName)
    {
        std::cout << "Creating weapon with ID: " << wIdGlobal_ << ". Name assinged: " << name_ << std::endl;
        wId_ = wIdGlobal_;
        wIdGlobal_++; 
    }

    bool Weapon::shoot(/*List modifier*/ const double distance)
    {
        std::cout << "**POW**\n";
        
        int diceRoll = rand() % 99 + 1;
        return diceRoll <= Modifiers::calculateAccuracy(baseAccuracy_, distance);
    }    
    
    Weapon::~Weapon()
    {
        std::cout << "Deleting weapon with ID: " << wId_ << std::endl; 
    }    
} // namespace entities
