#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>

int rm(const char *file_path) {
	struct stat statbuf;

	if (stat(file_path, &statbuf) != 0) {
		return 1;	
	}
	
	else if (remove(file_path) != 0) {
		return 1;	
	}
	
	else {
		return 0;	
	}
}

bool is_dir(const char *file_path) {
	struct stat statbuf;

	if (stat(file_path, &statbuf) != 0) {
		return NULL;	
	}
	
	else if (S_ISDIR(statbuf.st_mode) != 0) {
		return true;	
	}

	else {
		return false;	
	}
}

bool is_file(const char *file_path) {
	struct stat statbuf;

	if (stat(file_path, &statbuf) != 0) {
		return NULL;	
	}	

	else if (S_ISREG(statbuf.st_mode) != 0 ||
		S_ISLNK(statbuf.st_mode) != 0 ||
		S_ISFIFO(statbuf.st_mode) != 0) {
		
		return true;	
	}
	
	else {
		return false;	
	} 
}
