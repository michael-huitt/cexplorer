#include "dir_handler.h"
#include "file_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <menu.h>
#include <string.h>
#include <stdbool.h>

#define START_X 0
#define START_Y 0


void main(int argc, char *argv[]) {
	char *path;
	
	if (argv[1] == NULL) {
		path = "/";	
	}	
	
	char **dir_arr = populate_entries(path);	
	int x_max, y_max;
	unsigned int num_files = 0;	

	alphabetize(dir_arr);

	while (dir_arr[num_files] != NULL) {
		num_files++;	
	}

	initscr();
	cbreak();
	noecho();
	curs_set(0);	
	getmaxyx(stdscr, y_max, x_max);

	WINDOW *main_win = newwin(y_max, x_max, START_X, START_Y);
	keypad(main_win, true);	
	refresh();	
	
	box(main_win, START_X, START_Y);

	wrefresh(main_win);	
	
	bool quit_flag = false;	
	int selection;	
	int highlighted_entry = 0;	
	
	while(quit_flag != true) {
		for (int i = 0; i < num_files || i == y_max; i++) {
			if (i == highlighted_entry) {
				wattron(main_win, A_REVERSE);	
			}	
			
			mvwprintw(main_win, START_Y + 1 + i, START_X + 1, dir_arr[i]);	
			wattroff(main_win, A_REVERSE);	
		}	
		
		selection = wgetch(main_win);	
		
		switch(selection) {
			case (KEY_UP):
				highlighted_entry--;
				
				if (highlighted_entry < 0) {
					highlighted_entry = 0;	
				}	
				
				break;
			
			case (KEY_DOWN):
				highlighted_entry++;
				
				if (highlighted_entry >= y_max || highlighted_entry > (num_files - 1)) {
					highlighted_entry = (num_files - 1);	
				}
				
				break;			
	
			case ('q'):
				quit_flag = true;
				break;

			default:
				break;	
		}	
	}

	free(dir_arr);	
	endwin();	
}
