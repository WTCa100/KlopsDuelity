#include "./NIO.hpp"

#include <iostream>
// Stream In
namespace NI
{
    // This will imitate std::getline
    int getline(std::string& input) 
    {
        noecho();
        input.clear();  // clear the input string
        int cursor_pos = 0;  // initialize cursor position

        while (true) 
        {
            int ch = getch();  // get user input
            if (ch == '\n') {  // exit on Enter key
                break;
            } else if (ch == KEY_BACKSPACE || ch == 127) {  // handle backspace and delete keys
                if (!input.empty() && cursor_pos > 0) {
                    input.erase(cursor_pos - 1, 1);
                    cursor_pos--;
                    move(getcury(stdscr), getcurx(stdscr) - 1);
                    delch();
                    if(cursor_pos == input.length())
                    {
                        move(getcury(stdscr), getcurx(stdscr) - (input.length() - cursor_pos));
                    }
                }
            } else if (ch == KEY_LEFT) {  // move cursor left
                if (cursor_pos > 0) {
                    cursor_pos--;
                    move(getcury(stdscr), getcurx(stdscr) - 1);
                }
            } else if (ch == KEY_RIGHT) {  // move cursor right
                if (cursor_pos < input.length()) {
                    cursor_pos++;
                    move(getcury(stdscr), getcurx(stdscr) + 1);
                }
            } else if (isprint(ch)) {  // handle printable characters
                if (cursor_pos == input.length()) {
                    input += ch;
                    addch(ch);
                    cursor_pos++;
                } else {
                    input.insert(cursor_pos, 1, ch);
                    insch(ch);
                    cursor_pos++;
                    move(getcury(stdscr), getcurx(stdscr) + 1);
                }
            }
        }

        printw("\n");
        
        trimWhiteSpaces(input);

        echo();
        return input.length(); // return the length of the input string
    }

    void trimWhiteSpaces(std::string& uglyString)
    {
        // Remove spaces from the back
        while(uglyString[uglyString.size() - 1] == ' ' && !uglyString.empty())
        {
            uglyString.pop_back();
        }

        // Remove spaces from frnt
        while(uglyString[0] == ' ' && !uglyString.empty())
        {
            uglyString.erase(uglyString.begin());
        }

    }

} // namespace NI

// Stream out
namespace NO
{
    // Handle mouse events using threads    

} // namespace NO
