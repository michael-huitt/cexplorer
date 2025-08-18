#include "dir_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

#define PATH_BUFFER_SIZE 1024

//This function is a cast for the qsort
//in the alphabetize function as it expects
//integers for its last arg

int cmp_str(const void *a, const void *b) {
	const char *s1 = *(const char **)a;
	const char *s2 = *(const char **)b;
	
	return strcmp(s1, s2);
}

char** alphabetize(char **arr) {
	unsigned int i = 0;	
	
	while(arr[i] != NULL) {
		i++;	
	}	
	
	qsort(arr, i, sizeof(char*), cmp_str);
	
	return arr;
}

char* cd(char *path, char *dir) {
	char new_path[PATH_BUFFER_SIZE];

	if ((strlen(path)) + (strlen(dir)) + 2 > sizeof(new_path)) {
		return path;	
	}
	
	strncpy(new_path, path, sizeof(new_path));
	strncat(new_path, dir, sizeof(new_path) - strlen(new_path) - 1);

	if (new_path[strlen(new_path)] != '/') {
		new_path[strlen(new_path)] = '/';
		new_path[strlen(new_path) + 1] = '\0';	
	}

	return new_path;
}

char** populate_entries(const char *path){
	if (path == NULL) {
		perror("Missing/invalid arg for entry population");
		exit(EXIT_FAILURE);
	}	
	
	DIR *dir;
	struct dirent *ep;
	dir = opendir(path);
	unsigned int i = 0;	
	
	if (dir != NULL) {
		while (ep = readdir(dir)) { 
			i++;
		}	
	}	
	
	else {
		perror("Invalid directory");	
		exit(EXIT_FAILURE);	
	}	
	
	char **entries = malloc(sizeof(char*) * (i + 1));
	
	if (entries == NULL) {
		perror("Malloc error: populate_entries function");
		exit(EXIT_FAILURE);
	}	
	
	rewinddir(dir);	
	
	i = 0;	
	
	while ((ep = readdir(dir)) != NULL) {
		entries[i] = malloc(strlen(ep -> d_name) + 1);
		
		if (entries[i] == NULL) {
			perror("Malloc error: individual directory entry");
			exit(EXIT_FAILURE);	
		}	
		
		strcpy(entries[i], ep -> d_name);	
		
		i++;	
	}	
	
	closedir(dir);	
	
	entries[i] = NULL;	
	
	return entries; // !! DON'T FORGET TO FREE THE RETURNED ARRAY IN MAIN !!
}
