#include "./springfield1835.hpp"

namespace entities::weapons::muskets
{
    springfield1835::springfield1835()
    {
        std::cout << "Springfield created\n";
    }
    
    void springfield1835::present()
    {
        std::cout << "It's a springfield\n";
    }
    
    springfield1835::~springfield1835()
    {
        std::cout << "Springfield destroyed\n";
    }    
} // namespace entities::weapons::muskets



