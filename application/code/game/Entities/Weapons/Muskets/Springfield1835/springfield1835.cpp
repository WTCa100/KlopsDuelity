#include "./springfield1835.hpp"

#include <ncurses.h>

namespace entities::weapons::muskets
{
    Springfield1835::Springfield1835() : Weapon("Springfield model 1835")
    {
        basePrice_ = 120;
        baseDmg_ = 60;
        baseAccuracy_ = 0.25;
    }
    
    Springfield1835::~Springfield1835() {}    
} // namespace entities::weapons::muskets



