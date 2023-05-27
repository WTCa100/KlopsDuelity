#pragma once
#include <iostream>
#include <string>
#include <ctime>

const int MAX_PLAYER_CHARISMA_DISCOUNT = 60;

const std::string WEAPON_TYPE_PISTOL = "Pistol";
const std::string WEAPON_TYPE_MUSKET = "Musket";

namespace entities
{
    class Weapon
    {
    private:
        const std::string type_;
        static uint32_t wIdGlobal_;
    protected:
        std::string name_;
        double baseAccuracy_;
        double baseDmg_;
        double basePrice_;
        uint32_t wId_;
    public:
        Weapon();
        Weapon(std::string wName, std::string wType);
        void presentStats(bool isInShoop = false, int playerCharisma = 1);
        virtual bool shoot(const double distance);
        // Aim - raises accuracy but lowers reward (both honor and money)
        virtual ~Weapon();

        // Getters
        std::string getWeaponName() const {return name_;}
        double getWeaponBaseDmg() const {return baseDmg_;}
        double getWeaponBaseAccuracy() const {return baseAccuracy_;}
        double getWeaponBasePrice() const {return basePrice_;}
        double getWeaponModPrice(const int& playerCharisma = 1);
        std::string getWeaponType() const {return type_;}

    };

}
