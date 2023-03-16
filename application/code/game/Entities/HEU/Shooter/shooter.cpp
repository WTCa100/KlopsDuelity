#include <ctime>

#include "./shooter.hpp"

namespace entities::HEUTypes
{

    void Shooter::assingDefaultParemters(Shooter& modifyShooter)
    {
        modifyShooter.healthMax_ = 100;
        modifyShooter.health_ = modifyShooter.healthMax_;
        modifyShooter.isDead_ = false;
        modifyShooter.isConcious_ = true;
        if(modifyShooter.name_.empty())
        {
            modifyShooter.name_ = "no_name_assigned";
        }
        // Assing default values for every stat and change it later
        modifyShooter.statAim_ = 1;
        modifyShooter.statCharisma_ = 1;
        modifyShooter.statVitality_ = 1;
    }

    Shooter::Shooter() : currentlyHeldWeapon_(new entities::weapons::muskets::springfield1835)
    {
        assingDefaultParemters(*this);
        std::cout << "Shooter spawned\n";
    }

    Shooter::Shooter(bool isPlayer, std::string name) : HEU(isPlayer, name), currentlyHeldWeapon_(new entities::weapons::muskets::springfield1835)
    {
        assingDefaultParemters(*this);
        std::cout << "Shooter spawned\n";
        if(isPlayer_)
        {
            // Unless save was loaded
            duelsWonCount_ = 0;
            std::cout << "Shooter with " << hId_ << " is a player\n";
        }
        else
        {
            // Assing random value for now
            // Todo, make this number be close to player's 
            duelsWonCount_ = rand() % 301;
            std::cout << "Shooter with " << hId_ << " is not a player\n";
        }
    }


    void Shooter::fireWeapon(Shooter* target, const double distance)
    {
        std::cout << name_ << " fires his " << currentlyHeldWeapon_->getWeaponName() << std::endl;
        std::cout << "He is aiming at: " << target->name_ << std::endl;
        bool hasHit = currentlyHeldWeapon_->shoot(distance);
        std::cout << "!DEBUG --- " << name_ << " has ";
        if(hasHit)
        {
            double hitPoints = this->currentlyHeldWeapon_->getWeaponBaseDmg() / distance;
            std::cout << "hit his oponent!\n";
            // Dummy value for now
            target->health_ = target->health_ - hitPoints;
            std::cout << "!DEBUG --- NEW HEALTH " << target->health_ << std::endl;
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
            std::cout << "not hit his oponent!\n";
        }
    }

    void Shooter::pickWeapon()
    {
        std::cout << name_ << " said \" I will be using ";
        currentlyHeldWeapon_->present();
        std::cout << " for our duel!\"\n";
    }
    
    Shooter::~Shooter()
    {
        std::cout << "Shooter " << hId_ << " (" << name_ << ") despawned\n";
        delete currentlyHeldWeapon_;
    }
} // namespace entities::HEUTypes
