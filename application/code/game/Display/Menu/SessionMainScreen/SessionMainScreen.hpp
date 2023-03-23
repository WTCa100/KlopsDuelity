#pragma once

#include "../Menu.hpp"


enum SessionMainScreenOptions
{
    kQuit      = -1,
    kGoToArena = 1,
    kGoToShop  = 2
};

namespace Menus
{
    class SessionMainScreen : public Menu
    {
    private:
        SessionMainScreenOptions actionChoosen_;
    public:
        void mainDisplay() override;
        SessionMainScreenOptions getActionChoosen() const {return actionChoosen_;}
        SessionMainScreen(/* args */);
        ~SessionMainScreen();
    };
    
} // namespace Menus

