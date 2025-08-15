#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>

bool is_file(const char *file_path) {
	struct stat statbuf;

	if (stat(file_path, &statbuf) != 0) {
		//perror("stat fail (is_file)");	
		return false;	
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
