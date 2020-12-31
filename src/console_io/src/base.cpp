#include "base.hpp"
#include <algorithm>

using namespace console_io;

ncurses::ncurses()
{
        win_ptr = initscr();
        if (win_ptr == nullptr) {
                throw 1;
        }
        size_x = COLS;
        size_y = LINES;
}

ncurses::~ncurses()
{
        if (win_ptr == stdscr) { // guarantee Liskov substitution
                endwin();
        } else {
                if (parent != nullptr) {
                        parent->subwindows.erase(
                            std::find(parent->subwindows.begin(), parent->subwindows.end(), *this));
                }
                delwin(win_ptr);
        }
}
