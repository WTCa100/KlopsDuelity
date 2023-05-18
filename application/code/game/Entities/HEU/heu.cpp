#include "./heu.hpp"
 
#include <ncurses.h>

namespace entities
{

    HEU::HEU()
    {
        hId_ = hIdGlobal_;
        hIdGlobal_++;
    }

    HEU::HEU(bool isPlayer, std::string name) : isPlayer_(isPlayer), name_(name)
    {
        if(name.empty())
        {
            name_ = "John Smith";
            printw("Default name assigned: %s\n", name_.c_str());
        }

        hId_ = hIdGlobal_;
        hIdGlobal_++;
    }

    HEU::~HEU() {}

    uint32_t HEU::hIdGlobal_ = 0;

}
