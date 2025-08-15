#ifndef file_utils
#define file_utils

#include <stdbool.h>

//is_file simply checks whether a given path to something
//is a file using st_mode macros. Notably, all file types are
//grouped together: regular files, symbolic links, and pipe files
//will all return a true. This is more so because the actions
//that can be performed on these files are roughly the same
//right now
bool is_file(char *file_path);

#endif
