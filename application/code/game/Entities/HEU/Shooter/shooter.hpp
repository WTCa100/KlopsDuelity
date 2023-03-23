#pragma once
#include<iostream>
#include<string>

#include "../heu.hpp"

// Import all weapons
#include "../../Weapons/weapons.hpp"
#include "../../Weapons/Muskets/Springfield1835/springfield1835.hpp"

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

        public:
        void assingDefaultParemters(Shooter& modifyShooter);
        void pickWeapon();
        void fireWeapon(Shooter* target, const double distance);
        Shooter();
        Shooter(bool isPlayer, std::string name);
        virtual ~Shooter();
        
        // Functions below are mainly used for debug purposes 
        // Getters
        double getHealth() const {return health_;}
        // Setters
        void setHealth(const double& newHealth) {health_ = newHealth;}
        void setMaxHealth(const double& newHealthMax) {healthMax_ = newHealthMax; }
    };
    
} // namespace entities::HEUTypes