#include "./Town.hpp"

#include <ncurses.h>

namespace Graphics
{
    void Town::mainDisplay()
    {
        // Draw Town
        printw(" __________________________________________________________________\n");
        printw("|                  _____________                                   |\n");
        printw("|                 |             |                                  |\n");
        printw("|                 |  A R E N A  |                                  |\n");
        printw("|                 |_____________|                                  |\n");
        printw("|                /              \\                                 |\n");
        printw("|               /                \\                                |\n");
        printw("|                 |    | -- |   |                                  |\n");
        printw("|                                             _____________        |\n");
        printw("|                                            |             |       |\n");
        printw("|                        ^                   |   S H O P   |       |\n");
        printw("|                        |                   |_____________|       |\n");
        printw("|                      (YOU) - >               |         |         |\n");
        printw("|                                              |_________|         |\n");
        printw("|                                              |         |         |\n");                                                                        
        printw("|__________________________________________________________________|\n");
    }
} // namespace Display::Graphics
