#include <stddef.h>

#ifndef dir_handler
#define dir_handler

//Populates an array with a given directory (char *path)'s
//contents and returns it.
//NOTE: The returned array of strings MUST be freed in main. The reason
//an array of strings is created is to make functions which depend on knowing
//the size of the directory easier.

char** populate_entries(const char *path);

//Given an array of strings, alphabetize will take the contents
//of it and order the elements such that they are in
//alphabetical order.

char** alphabetize(char **arr);

//cd aims to replicate the functionality of a cli 'change directory'
//command. Conventions like '..' are used to move up the file
//hiearchy.

void cd(char *path, char *dir, char *new_path, size_t buffer);

#endif
