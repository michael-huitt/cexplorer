#ifndef ui
#define ui

#include <ncurses.h>

/* screen_init handles initializing ncurses
 * with general settings such as noecho() */

void screen_init();

struct win_size { //for find_max_xy to store screen size
	int x;
	int y;
};

/* find_max_xy takes a pointer to type WINDOW
 * and returns a structure with members .x and .y,
 * representing the size of the window in terms of
 * rows and columns */

struct win_size find_max_xy(WINDOW *window);

#endif
