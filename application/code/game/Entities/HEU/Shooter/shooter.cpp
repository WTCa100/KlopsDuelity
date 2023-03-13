#include "./shooter.hpp"

namespace entities::HEUTypes
{

    void Shooter::assingDefaultParemters(Shooter& modifyShooter)
    {
        modifyShooter.health_ = 100;
        modifyShooter.isDead_ = false;
        modifyShooter.isConcious_ = true;
        if(modifyShooter.name_.empty())
        {
            modifyShooter.name_ = "Dummy!";
        }
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
            std::cout << "Shooter with " << hId_ << " is a player\n";
        }
        else
        {
            std::cout << "Shooter with " << hId_ << " is not a player\n";
        }
    }

    void Shooter::fireWeapon(Shooter* target)
    {
        std::cout << name_ << " fires his " << currentlyHeldWeapon_->getWeaponName() << std::endl;
        std::cout << "He is aiming at: " << target->name_ << std::endl;
        bool hasHit = currentlyHeldWeapon_->shoot();
        std::cout << "!DEBUG --- " << name_ << " has ";
        if(hasHit)
        {
            std::cout << "hit his oponent!\n";
            // Dummy value for now
            target->health_ = target->health_ - 15;
            std::cout << "!DEBUG --- NEW HEALTH " << target->health_ << std::endl;
        }
        else
        {
            std::cout << "not hit his oponent!\n";
        }
    }

    void Shooter::presentWeapon()
    {
        currentlyHeldWeapon_->present();
    }
    
    Shooter::~Shooter()
    {
        std::cout << "Shooter " << hId_ << " (" << name_ << ") despawned\n";
        delete currentlyHeldWeapon_;
    }
} // namespace entities::HEUTypes
