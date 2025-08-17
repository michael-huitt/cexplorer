#include "dir_handler.h"
#include "file_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <menu.h>
#include <string.h>
#include <stdbool.h>

#define WIN_HEIGHT 30
#define WIN_WIDTH 90
#define START_X 0
#define START_Y 0


void main(int argc, char *argv[]) {
	char *path = argv[1];
	char **arr = populate_entries(path);	
	int x_max, y_max;

	initscr();
	cbreak();
	noecho();

	getmaxyx(stdscr, y_max, x_max);

	WINDOW *main_win = newwin(y_max, x_max, START_X, START_Y);
	refresh();	
	
	box(main_win, 0, 0);
	wrefresh(main_win);
	
	getch();
	
	free(arr);	
	endwin();	
}
