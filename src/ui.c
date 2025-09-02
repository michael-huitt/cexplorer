#include <ncurses.h>

void screen_init() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
}

