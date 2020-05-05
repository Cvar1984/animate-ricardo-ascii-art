/**
 * Copyright (c) 2020 Ramdhan Firmansyah
 * File              : animate.cpp
 * Author            : Cvar1984 <gedzsarjuncomuniti@gmail.com>
 * Date              : 30.04.2020
 * Last Modified Date: 30.04.2020
 * Last Modified By  : Cvar1984 <gedzsarjuncomuniti@gmail.com>
 */

#ifndef ANIMATE_HPP
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
        int height, width, sheight, swidth;

    public:
        bool colors;

        Animation(
                bool colors = false,
                int height = 0,
                int width = 0,
                int sheight = 0,
                int swidth = 0
                )
        {
            initscr();
            cbreak();
            noecho();
            curs_set(0); // hide cursors

            if(colors && has_colors()) {
                this->colors = true;
                start_color();
            }

            this->height = height;
            this->width = width;
            this->sheight = sheight;
            this->swidth = swidth;
            this->win = newwin(height, width, sheight, swidth);
        }

        bool generateFrame(vector<string> frame)
        {
            for(int x = 0; x < (int)frame.size(); x++) {
                ifstream file;
                file.open(frame[x]); // open fstream frame
                if(!file) return false;
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
            int size = (int)this->animation.size();

            for(int x = 0; x < size; x++) {

                if(this->colors) {
                    init_pair(1, x, COLOR_BLACK);
                    wattron(this->win, A_BOLD);
                    wattron(this->win, COLOR_PAIR(1));
                }

                mvwprintw(this->win, this->sheight, this->swidth, this->animation[x].c_str()); // print all frame
                wrefresh(this->win); // render to the screen
                usleep(speed);
            }
        }

        ~Animation()
        {
            delwin(this->win); // delete window
            endwin(); // close window
        }
};
#endif
