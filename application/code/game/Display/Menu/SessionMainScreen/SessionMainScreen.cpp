#include "./SessionMainScreen.hpp"

#include "../../Graphical/Town/Town.hpp"

#include <ncurses.h>

namespace Menus
{
    void SessionMainScreen::mainDisplay()
    {
        Display* townDisp = new Graphics::Town();
        // Get input
        bool exitLoop;
        while(!exitLoop)
        {
            townDisp->mainDisplay();
            printw("Use arrow keys to move\n");
            printw("Press 'q' to quit\n");
            refresh();
            int input = getch();
            switch (input)
            {
            case KEY_RIGHT:
            case 'D':
            case 'd':
                actionChoosen_ = SessionMainScreenOptions::kGoToShop;
                exitLoop = true;
                break;
            case KEY_UP:
            case 'W':
            case 'w':
                actionChoosen_ = SessionMainScreenOptions::kGoToArena;
                exitLoop = true;
                break;
            case 'q':
                actionChoosen_ = SessionMainScreenOptions::kQuit;
                exitLoop = true;
                break;
            default:
                printw("Please enter valid option!\n");
                getch();
                break;
            }
            clear();        
            refresh();
        }        
    }

    SessionMainScreen::SessionMainScreen()
    {
        // Initialize Ncurses
        initscr();
        refresh(); // Match screen refresh
        keypad(stdscr, TRUE); // Enable keypad 
        cbreak(); // Enbale line buffering
        noecho(); // Disable input echoing        
    }

    SessionMainScreen::~SessionMainScreen()
    {
        // Destruct Ncurses
        clear();
        refresh();
        endwin();
    }
} // namespace Menus
