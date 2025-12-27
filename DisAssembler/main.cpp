#include <iostream>
#include <ncurses.h> 
#include <filesystem>
#include "converter.h"

bool CheckIfExe(std::string file) {
     std::filesystem::path p(file);
     if (p.has_extension()) {
          if (p.extension() == ".exe") {
               return true;
          }
          else {
               return false;
          }
     }
     else {
          return true;
     }
}

int main(int argc, char *argv[]) {
     std::vector<std::string> lines;
     if (argc > 1) {
          if (CheckIfExe(argv[1]) && std::filesystem::exists(argv[1])) {
               std::ifstream file(argv[1], std::ios::binary);
               std::string format {};
               char header[4];
               file.seekg(0);
               file.read(header, sizeof(header));

               if (file.gcount() < 4) {
                    std::cerr << "Error: File is too small" << std::endl;
                    std::cerr.flush();
                    return 1;
               }
               
               
               if (header[0] == 0x7F && header[1] == 'E' && header[2] == 'L' && header[3] == 'F') {
                    format = "ELF";
               }
               else if (header[0] == 'M' && header[1] == 'Z'){
                    format = "WIN";
               }
               else { 
                    std::cerr << "Unknown file header" << std::endl;
                    std::cerr.flush();
                    return 1;
               }
               file.clear();
               Parse(lines, format, file);
               if (lines.empty()) {
                    endwin();
                    return 1;
               }
          } else {
               endwin();
               std::cerr << "Error: Wrong extension of file or file don't exist: " << argv[1] << std::endl;
               std::cerr.flush();
               return 1;
          }
     } else {
          std::cerr << "No arguments found" << std::endl;
          endwin();
          return 1;
     }   
     int offset = 0;
     int ch {};
     bool running = true;
     size_t max_y {}, max_x{};
     initscr();                  // Enter into curses-mode
     cbreak();                   // No buffer
     noecho();                   // No echo of pressed buttons
     keypad(stdscr, TRUE);       // Turn on arrow buttons
     clear();
     while (running) {
          getmaxyx(stdscr, max_y, max_x);
          erase();
          for (size_t i = 0; (i < max_y && (i + offset) < lines.size()); ++i) {
               mvprintw(i, 0, "%s", lines[i + offset].c_str());
          }

          mvprintw(max_y - 1, 0, "Up and Down for scroll | q: Exit");
          clrtoeol();
          refresh();
          ch = getch();
          switch (ch) {
               case KEY_UP:
                    if (offset > 0) offset--;
                    break;
               case KEY_DOWN:
                    if (offset + max_y < lines.size()) offset++;
                    break;
               case 'q':
                    running = false;
                    break;
          }
     }

     endwin();
     return 0;
}
