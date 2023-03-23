#pragma once
#include <iostream>
#include <string>
#include <ctime>

namespace entities
{
    class Weapon
    {
    private:
        static uint32_t wIdGlobal_;
    protected:
        std::string name_;
        double baseAccuracy_;
        double baseDmg_;
        double basePrice_;
        uint32_t wId_;
    public:
        Weapon();
        Weapon(std::string wName);
        virtual void present() = 0;
        virtual bool shoot(const double distance);
        // Aim - raises accuracy but lowers reward (both honor and money)
        virtual ~Weapon();

        // Getters
        std::string getWeaponName() const {return name_;}
        double getWeaponBaseDmg() const {return baseDmg_;}
        double getWeaponBaseAccuracy() const {return baseAccuracy_;}
        double getWeaponBasePrice() const {return basePrice_;}

    };

}
