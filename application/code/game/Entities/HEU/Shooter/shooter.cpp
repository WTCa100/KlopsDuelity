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

    }

    Shooter::Shooter() : currentlyHeldWeapon_(new entities::weapons::muskets::springfield1835)
    {
        assingDefaultParemters(*this);
        printw("Shooter spawned\n"); 
    }

    Shooter::Shooter(bool isPlayer, std::string name) : HEU(isPlayer, name), currentlyHeldWeapon_(new entities::weapons::muskets::springfield1835)
    {
        assingDefaultParemters(*this);
        printw("Shooter spawned\n"); 
        if(isPlayer_)
        {
            // Unless save was loaded
            duelsWonCount_ = 0;
            printw("Shooter with %d is a player\n", hId_);
            // TODO: Make player pick weapon his weapon
        }
        else
        {
            // Assing random value for now
            // Todo, make this number be close to player's 
            duelsWonCount_ = rand() % 301;
            printw("Shooter with %d is not a player\n", hId_);
        }
    }


    void Shooter::fireWeapon(Shooter* target, const double distance)
    {
        printw("%s fires his %s\n", name_.c_str(), currentlyHeldWeapon_->getWeaponName().c_str());
        printw("He is aiming at: %s\n", target->name_.c_str());
        bool hasHit = currentlyHeldWeapon_->shoot(distance);
        printw("!DEBUG --- %s has ", name_.c_str());
        if(hasHit)
        {
            double hitPoints = this->currentlyHeldWeapon_->getWeaponBaseDmg() / distance;
            printw("Hits his oponent\n");
            // Dummy value for now
            target->health_ = target->health_ - hitPoints;
            printw("!DEBUG --- NEW HEALTH %.2f\n", target->getHealth());
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
        currentlyHeldWeapon_->present();
        printw(" for the duel!\"\n");
    }
    
    Shooter::~Shooter()
    {
        printw("Shooter %d ( %s ) despawned", hId_, name_.c_str());
        delete currentlyHeldWeapon_;
    }
} // namespace entities::HEUTypes
