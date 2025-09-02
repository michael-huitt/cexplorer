#include <menu.h>
#include "ui.h"

void screen_init() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
}

struct win_size find_max_xy(WINDOW *window) {
	struct win_size size;
	
	getmaxyx(window, size.y, size.x);
	return size;
}
