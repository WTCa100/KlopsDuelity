#include <ctime>
#include <ncurses.h>

#include "./shooter.hpp"

// Get modifiers
#include "../../../Modifiers/Modifiers.hpp"

namespace entities::HEUTypes
{

    void Shooter::assingDefaultParemters(Shooter& modifyShooter)
    {
        modifyShooter.isDead_ = false;
        modifyShooter.isConcious_ = true;
        if(modifyShooter.name_.empty())
        {
            modifyShooter.name_ = "no_name_assigned";
        }
        // Assing default values for every stat and change it later if an entity is not a player
        if(!isPlayer_)
        {
            modifyShooter.statAim_      = 0;
            modifyShooter.statCharisma_ = 0;
            modifyShooter.statVitality_ = 0;
            // Assign members based on stats
            modifyShooter.healthMax_ = Modifiers::calculateHealth(modifyShooter.statVitality_);
            modifyShooter.health_ = modifyShooter.healthMax_;
        }

        if(modifyShooter.currentlyHeldWeapon_)
        {
            power_ = Modifiers::calculateEntityPower(modifyShooter.statAim_, modifyShooter.statVitality_, modifyShooter.statCharisma_) + 
                     Modifiers::calculateWeaponPower(modifyShooter.currentlyHeldWeapon_->getWeaponBaseAccuracy(), modifyShooter.currentlyHeldWeapon_->getWeaponBaseDmg());
        }
        else
        {
            power_ = Modifiers::calculateEntityPower(modifyShooter.statAim_, modifyShooter.statVitality_, modifyShooter.statCharisma_);
        }

    }

    Shooter::Shooter() : currentlyHeldWeapon_(nullptr)
    {
        assingDefaultParemters(*this);
    }

    Shooter::Shooter(bool isPlayer, std::string name) : HEU(isPlayer, name), currentlyHeldWeapon_(nullptr), duelsWonCount_(0)
    {
        assingDefaultParemters(*this);
    }


    void Shooter::setStats(const int& newStatAim, const int& newStatVitality, const int& newStatCharisma)
    {  
        statAim_ = newStatAim;
        statVitality_ = newStatVitality;
        // Adjust max/current health
        healthMax_ = Modifiers::calculateHealth(statVitality_);
        health_    = Modifiers::calculateHealth(statVitality_);
        statCharisma_ = newStatCharisma;

        evaluatePower();
    }

    void Shooter::evaluatePower()
    {
        // Check if entity has weapons
        if(currentlyHeldWeapon_)
        {
            power_ = Modifiers::calculateEntityPower(statAim_, statVitality_, statCharisma_) + 
                     Modifiers::calculateWeaponPower(currentlyHeldWeapon_->getWeaponBaseAccuracy(), currentlyHeldWeapon_->getWeaponBaseDmg());
        }
        else
        {
            power_ = Modifiers::calculateEntityPower(statAim_, statVitality_, statCharisma_);
        }
    }

    void Shooter::setStatVit(const int& newStatVit) 
    { 
        statVitality_ = newStatVit;
        // Adjust max/current health        
        healthMax_ = Modifiers::calculateHealth(statVitality_);
        health_    = Modifiers::calculateHealth(statVitality_); 
        evaluatePower();
    }    

    void Shooter::setStatCharisma(const int& newStatCharisma)
    {
        statCharisma_ = newStatCharisma;
        evaluatePower();
    }

    void Shooter::setStatAim(const int& newStatAim)
    {
        statAim_ = newStatAim;
        evaluatePower();
    }

    void Shooter::fireWeapon(Shooter* target, const double distance)
    {
        printw("%s fires his %s\n", name_.c_str(), currentlyHeldWeapon_->getWeaponName().c_str());
        printw("He is aiming at: %s\n", target->name_.c_str());
        bool hasHit = currentlyHeldWeapon_->shoot(distance);
        if(hasHit)
        {
            double hitPoints = this->currentlyHeldWeapon_->getWeaponBaseDmg() / distance;
            printw("Hits his oponent, dealing %.2f dmg\n", hitPoints);
            // Dummy value for now
            target->health_ = target->health_ - hitPoints;
            if(target->health_ <= 0)
            {
                target->isConcious_ = false;
                if(target->health_ <= -20)
                {
                    target->isDead_ = true;
                }
            }
        }
        else
        {
            printw("not hit his oponent\n");
        }
    }

    void Shooter::pickWeapon()
    {
        if(isPlayer_)
        {
            printw("Pick your weapon: \n");
            getch();
        }

        printw("%s said \"I will be using ", name_.c_str());
        currentlyHeldWeapon_->presentStats();
        printw(" for the duel!\"\n");
    }
    
    void Shooter::setCurrentlyHeldWeapon(entities::Weapon* newWeapon)
    {
        currentlyHeldWeapon_ = newWeapon;
        evaluatePower();
    }

    Shooter::~Shooter()
    {
        if(currentlyHeldWeapon_)
        {
            delete currentlyHeldWeapon_;
        }
    }

} // namespace entities::HEUTypes
