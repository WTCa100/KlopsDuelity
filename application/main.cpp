#include <iostream>
#include <ctime>

#include "./code/utilities/Application/Application.hpp"

#include <ncurses.h>
#include "./code/utilities/IOStream/NIO.hpp"

int main()
{
    // Initialize necessery functionality
    // Generate seed
    srand(time(NULL));

    // Initialize ncurses
    initscr();
    refresh(); // Match screen refresh
    keypad(stdscr, TRUE); // Enable keypad 
    cbreak(); // Enbale line buffering

    printw("Hello world!\n");
    
    Application* gameApp = Application::getInstance();
    // Check files
    // Start app
    gameApp->startApp();
    delete gameApp;

    getch();
    endwin();
    return 0;
}
