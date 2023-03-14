#include "./springfield1835.hpp"

namespace entities::weapons::muskets
{
    springfield1835::springfield1835() : Weapon("Springfield model 1835")
    {
        baseDmg_ = 60;
        baseAccuracy_ = 0.25;
        std::cout << "Springfield created\n";
    }
    
    void springfield1835::present()
    {
        std::cout << name_;
    }
    
    springfield1835::~springfield1835()
    {
        std::cout << "Springfield destroyed\n";
    }    
} // namespace entities::weapons::muskets



