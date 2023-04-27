#pragma once

#include "../../Display.hpp"

#include <ncurses.h>

namespace Graphics
{
    class Arena : public Display
    {
    private:
        int drawDistance_;
    public:
        void makeArena(const int& drawDistance, WINDOW* arenaBox);
        void mainDisplay() override;
        Arena() = default;
        ~Arena() = default;      
    };
} // namespace Graphics
