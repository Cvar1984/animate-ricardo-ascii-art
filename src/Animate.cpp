/**
 * Copyright (c) 2020 Ramdhan Firmansyah
 * File              : animate.cpp
 * Author            : Cvar1984 <gedzsarjuncomuniti@gmail.com>
 * Date              : 30.04.2020
 * Last Modified Date: 30.04.2020
 * Last Modified By  : Cvar1984 <gedzsarjuncomuniti@gmail.com>
 */

#include <ncurses.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;
using std::stringstream;

class Animation {

    protected:

        vector<string> animation; // big data vector
        vector<string> frame;
        WINDOW *win;

    public:

        Animation(int x, int y, int s_x, int s_y)
        {
            initscr();
            cbreak();
            noecho();
            curs_set(0); // hide cursors

            this->win = newwin(x, y, s_x, s_y);
        }

        bool generateFrame(vector<string> frame)
        {
            for(int x = 0; x < (int)frame.size(); x++) {
                ifstream file;
                file.open(frame[x]); // open fstream frame

                if(!file) {
                    return false;
                }

                stringstream buff;
                buff << file.rdbuf(); // assign to stringstream buffer
                file.close(); // close ifstream
                string frame = buff.str(); // create frame of string from stringstream buffer
                this->animation.push_back(frame); // stack frame to vector animation
            }
            return true;
        }

        void play(int speed)
        {
            for(int x = 0; x < (int)this->animation.size(); x++) {
                mvprintw(0, 0, this->animation[x].c_str()); // print all frame
                refresh(); // refresh screen
                usleep(speed);
                clear(); // clear screen
            }
        }

        ~Animation()
        {
            wrefresh(this->win); // refresh window
            endwin(); // close window
        }
};
