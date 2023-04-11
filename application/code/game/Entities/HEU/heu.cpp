#include "./heu.hpp"
 
#include <ncurses.h>

namespace entities
{

    HEU::HEU()
    {
        printw("Creation of Human Entity Unit\n");
        hId_ = hIdGlobal_;
        hIdGlobal_++;
    }

    HEU::HEU(bool isPlayer, std::string name) : isPlayer_(isPlayer), name_(name)
    {
        if(!name.empty())
        {
            printw("Name assigned: %s , isPlayer assigned: %d\n", name_.c_str(), isPlayer_);
        }
        else
        {
            printw("Name empty, isPlayer assigned: %d\n", isPlayer_);
            name_ = "no_player_name";
            printw("Default name assigned: %s\n", name_.c_str());
        }


        printw("Creation of Human Entity Unit\n");
        hId_ = hIdGlobal_;
        hIdGlobal_++;
    }

    HEU::~HEU()
    {
        printw("Destruction of Hman Entity Unit\n");
        getch();
    }

    uint32_t HEU::hIdGlobal_ = 0;

}
