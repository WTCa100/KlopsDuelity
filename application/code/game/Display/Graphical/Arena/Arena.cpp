#include "./Arena.hpp"

namespace Graphics
{

    void Arena::makeArena(const int& drawDistance, WINDOW* arenaBox)
    {
        drawDistance_ = drawDistance;
        const int minimalDistance = 10;
        const int heuOffset = 3;

        // draw enemy
        box(arenaBox, 0, 0);
        mvwprintw(arenaBox, 3, heuOffset, " E");
        mvwprintw(arenaBox, 4, heuOffset, " O______ ");
        mvwprintw(arenaBox, 5, heuOffset, "\\|\\/");    
        mvwprintw(arenaBox, 6, heuOffset, " | ");
        mvwprintw(arenaBox, 7, heuOffset, "/ \\");
        mvwprintw(arenaBox, 8, heuOffset, "| |");

        // draw player
        mvwprintw(arenaBox, 3, heuOffset + drawDistance_ + minimalDistance, "       P");
        mvwprintw(arenaBox, 4, heuOffset + drawDistance_ + minimalDistance, " ______O");
        mvwprintw(arenaBox, 5, heuOffset + drawDistance_ + minimalDistance, "     \\/|/");    
        mvwprintw(arenaBox, 6, heuOffset + drawDistance_ + minimalDistance, "       | ");
        mvwprintw(arenaBox, 7, heuOffset + drawDistance_ + minimalDistance, "      / \\");
        mvwprintw(arenaBox, 8, heuOffset + drawDistance_ + minimalDistance, "      | |");

        wrefresh(arenaBox);
        move(11, 0);
        refresh();
        mainDisplay();
    }

    void Arena::winScreen(const bool& hasPlayerWon)
    {
        hasPlayerWon ? printw(" P \n") : printw(" E \n");
        printw("| |\n");
        printw("\\O/\n");
        printw(" | \n");
        printw(" | \n");
        printw("/ \\\n");
        printw("| |\n");
    }

    void Arena::mainDisplay()
    {
        printw("Distance: %d\n", drawDistance_);
    }

} // namespace Graphics
