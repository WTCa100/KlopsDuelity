#include "./moukahla.hpp"

#include <ncurses.h>

namespace entities::weapons::muskets
{
    
    Moukahla::Moukahla() : Weapon("Moukahla")
    {
        basePrice_ = 100;
        baseDmg_ = 35;
        baseAccuracy_ = 0.23;
    }
    
    Moukahla::~Moukahla() = default;
    
} // namespace entities::weapons::muskets
