#include "./moukahla.hpp"

#include <ncurses.h>

namespace entities::weapons::muskets
{
    
    Moukahla::Moukahla() : Weapon("Moukahla")
    {
        basePrice_ = 100;
        baseDmg_ = 35;
        baseAccuracy_ = 0.23;
        printw("Moukahla created\n");
    }

    void Moukahla::present()
    {
        printw("%s", name_.c_str());
    }

    Moukahla::~Moukahla()
    {
        printw("Moukahla destroyed\n");
    }
    
} // namespace entities::weapons::muskets
