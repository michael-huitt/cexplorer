#ifndef file_utils
#define file_utils

#include <stdbool.h>

bool is_dir(const char *file_path);

//is_file simply checks whether a given path to something
//is a file using st_mode macros. Notably, all file types are
//grouped together: regular files, symbolic links, and pipe files
//will all return a true. This is more so because the actions
//that can be performed on these files are roughly the same
//right now

bool is_file(char *file_path);

//rm attempts to remove a file given within a file path, first it checks
//if the file exists, if it doesn't, it returns non zero, then it attempts
//to remove the file, if that fails, it returns non zero, if both checks
//pass then the function returns a 0 to indicate success

int rm(const char *file_path);

#endif
