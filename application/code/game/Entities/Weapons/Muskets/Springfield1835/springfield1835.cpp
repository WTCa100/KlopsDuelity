#include "./springfield1835.hpp"

#include <ncurses.h>

namespace entities::weapons::muskets
{
    springfield1835::springfield1835() : Weapon("Springfield model 1835")
    {
        basePrice_ = 120;
        baseDmg_ = 60;
        baseAccuracy_ = 0.25;
        printw("Springfield model 1835 created\n");
    }
    
    void springfield1835::present()
    {
        printw("%s", name_.c_str());
    }
    
    springfield1835::~springfield1835()
    {
        printw("Springfield model 1835 destroyed\n");
    }    
} // namespace entities::weapons::muskets



