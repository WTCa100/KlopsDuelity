#include "./shooter.hpp"

namespace entities::HEUTypes
{
    Shooter::Shooter()
    {
        std::cout << "Shooter spawned\n";
    }
    
    Shooter::~Shooter()
    {
        std::cout << "Shooter despawned\n";
    }
} // namespace entities::HEUTypes
