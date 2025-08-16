CEXPLORER - A TUI based file browser using ncurses
==================================================
!! Work in progress !!

Installation / Requirements
------------
  - Linux
  - Ncurses (Most linux distributions include ncurses by default,
    for development, the dev library is required)
  - CMake (For devlopment: required to make builds)

How to build
------------
  - On bash:
  ```
git clone https://github.com/michael-huitt/cexplorer.git
cd cexplorer/build
cmake ..
make
```
Roadmap
-------
  Current features:
  - Functional/modular C backend

  In progress:
  - User interface

  Planned:
  - Directory manipulation (recursively delete files in a directory)
  - vifm style macros
  - Polishing and documentation

License: This project is licensed under the GNU GPL v3.0 license [https://www.gnu.org/licenses/gpl-3.0.en.html]
