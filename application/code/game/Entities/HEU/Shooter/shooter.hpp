#pragma once
#include<iostream>
#include<string>
#include<map>

#include "../heu.hpp"

// Import all weapons
#include "../../Weapons/weapons.hpp"
#include "../../Weapons/Muskets/Springfield1835/springfield1835.hpp"
#include "../../Weapons/Muskets/Moukahla/moukahla.hpp"

class Duel;

namespace entities::HEUTypes
{
    class Shooter : public HEU
    {
        friend class ::Duel;        
        private:
        Weapon* currentlyHeldWeapon_;
        
        /// @brief If shooter health drop below 20 hp he will die
        bool isDead_;
        /// @brief Health is lower than 0 but greater than 20
        bool isConcious_;
        
        protected:
        double healthMax_;
        double health_;
        uint32_t duelsWonCount_;
        // Skill values
        uint16_t statAim_;
        uint16_t statVitality_;
        uint16_t statCharisma_;

        uint32_t power_;

        public:
        void assingDefaultParemters(Shooter& modifyShooter);
        void evaluatePower();
        void pickWeapon();
        void fireWeapon(Shooter* target, const double distance);
        Shooter();
        Shooter(bool isPlayer, std::string name);
        virtual ~Shooter();
    
        // Functions below are mainly used for debug purposes 
        // Getters
        double getHealth() const { return health_; }
        double getMaxHealth() const { return healthMax_; }
        int getStatAim() const { return statAim_; }
        int getStatVit() const { return statVitality_; }
        int getStatCharisma() const { return statCharisma_; }
        int getPower() const { return power_; }
        entities::Weapon* getCurrentlyHeldWeapon() const { return currentlyHeldWeapon_; }

        // Setters
        void setHealth(const double& newHealth) {health_ = newHealth;}
        void setMaxHealth(const double& newHealthMax) {healthMax_ = newHealthMax; }
        void setStats(const int& newStatAim, const int& newStatVitality, const int& newStatCharisma);
        void setCurrentlyHeldWeapon(entities::Weapon* newWeapon);
        void setStatAim(const int& newStatAim);
        void setStatVit(const int& newStatVit);
        void setStatCharisma(const int& newStatCharisma);

    };
    
} // namespace entities::HEUTypes