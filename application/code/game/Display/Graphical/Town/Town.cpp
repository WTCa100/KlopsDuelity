#include "./Town.hpp"

#include <ncurses.h>

namespace Graphics
{
    void Town::mainDisplay()
    {
        // Draw Town
        printw(" ___________________________________________________________________________\n");
        printw("|                           _____________                                   |\n");
        printw("|                          |             |                                  |\n");
        printw("|                          |  A R E N A  |                                  |\n");
        printw("|                          |_____________|                                  |\n");
        printw("|                         /              \\                                  |\n");
        printw("|                        /                \\                                 |\n");
        printw("|     _____________        |    | -- |   |                                  |\n");
        printw("|    |             |                                                        |\n");
        printw("|    |  C A B I N  |                                   _____________        |\n");
        printw("|    |_____________|                                  |             |       |\n");         
        printw("|        ______                   ^                   |   S H O P   |       |\n");
        printw("|      /      /\\                  |                   |_____________|       |\n");
        printw("|    /      /    \\          <-  (YOU) - >               |         |         |\n");
        printw("|  /______/________\\                                    |_________|         |\n");
        printw("|  |     |         |                                    |         |         |\n");
        printw("|  |     |    _    |                                                        |\n");           
        printw("|  |_____|__ |-|___|                                                        |\n");  
        printw("|                                                                           |\n");                                                            
        printw("|___________________________________________________________________________|\n");
    }
} // namespace Display::Graphics
