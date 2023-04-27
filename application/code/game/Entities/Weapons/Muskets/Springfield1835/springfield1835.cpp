#include "./springfield1835.hpp"

#include <ncurses.h>

namespace entities::weapons::muskets
{
    Springfield1835::Springfield1835() : Weapon("Springfield model 1835")
    {
        basePrice_ = 120;
        baseDmg_ = 60;
        baseAccuracy_ = 0.25;
        printw("Springfield model 1835 created\n");
    }
    
    Springfield1835::~Springfield1835()
    {
        printw("Springfield model 1835 destroyed\n");
    }    
} // namespace entities::weapons::muskets



