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
        double accuracy_;
        double dmg_;
        uint32_t wId_;
    public:
        virtual std::string getWeaponName() const {return name_;}
        Weapon(/* args */);
        Weapon(std::string wName);
        virtual void present() = 0;
        virtual bool shoot();
        // Aim - raises accuracy but lowers reward (both honor and money)
        virtual ~Weapon();
    };

}
