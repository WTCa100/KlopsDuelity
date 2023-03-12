#include "./shooter.hpp"

namespace entity
{

    shooter::shooter()
    {
        // Default weapon is gonna be springfield
        heldWeapon_ = new Springfield1835;
        std::cout << "Shooter created\n";
    }
    
    shooter::shooter(bool isPlayer) 
    {
        //heldWeapon_ = new Springfield1835;
        //if(isPlayer_)
        //{
        //    std::cout << "Player shooter instance created\n";
        //}
        //else
        //{
        //    std::cout << "Non-player shooter instance created\n"; 
        //}
    }

    void shooter::showWeapon()
    {
        std::cout << "Look at that bad boy!\n";
        //heldWeapon_->present();
    }

    shooter::~shooter()
    {
        std::cout << "Shooted destroyed\n";
        //delete heldWeapon_;
    }


} // namespace entity