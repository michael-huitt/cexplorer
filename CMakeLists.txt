cmake_minimum_required(VERSION 3.25)
project(cexplorer C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER gcc)

include_directories(include)

set(SOURCES
	src/main.c
	
	src/dir_handler.c
	src/dir_handler.h
	
	src/file_utils.c
	src/file_utils.h

	src/ui.c
	src/ui.h
)
add_compile_options(-g)
add_executable(cexplorer ${SOURCES})
target_link_libraries(cexplorer ncurses menu)
