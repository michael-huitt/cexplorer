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
	initscr();
	cbreak();
	noecho();
	
	WINDOW *win = newwin(WIN_HEIGHT, WIN_WIDTH, START_X, START_Y);
	refresh();	
	
	char *path = argv[1];	
	char **arr = populate_entries(path);
	
	box(win, 0, 0);
	wrefresh(win);
	
	getch();
	
	free(arr);	
	endwin();	
}
