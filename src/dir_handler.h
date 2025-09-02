#include <stddef.h>

#ifndef dir_handler
#define dir_handler

/* Populates an array with a given directory path
 * with the names of all the files within it. Note
 * that the resulting array must be freed.*/

char** populate_entries(const char *path);

/* Given an array of strings, alphabetize will take the contents
 * of it and order the elements such that they are in
 * alphabetical order.*/

char** alphabetize(char **arr);

/* cd aims to replicate the functionality of a cli 'change directory'
 * command. Conventions like '..' are used to move up the file
 * hiearchy. */

void cd(char *path, char *dir, char *new_path, size_t buffer);

#endif
