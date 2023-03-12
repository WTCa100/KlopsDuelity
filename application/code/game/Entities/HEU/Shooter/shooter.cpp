#include "./shooter.hpp"

namespace entities::HEUTypes
{
    Shooter::Shooter() : currentlyHeldWeapon_(new entities::weapons::muskets::springfield1835)
    {
        std::cout << "Shooter spawned\n";
    }

    void Shooter::presentWeapon()
    {
        currentlyHeldWeapon_->present();
    }
    
    Shooter::~Shooter()
    {
        std::cout << "Shooter despawned\n";
        delete currentlyHeldWeapon_;
    }
} // namespace entities::HEUTypes
