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
        bool color;

    public:

        Animation(int height, int width, int sheight, int swidth)
        {
            initscr();
            cbreak();
            noecho();
            curs_set(0); // hide cursors

            if(has_colors()) {
                start_color();
                this->color = true;
            }


            this->win = newwin(height, width, sheight, swidth);
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
            int size = (int)this->animation.size();

            for(int x = 0; x < size; x++) {
                if(this->color) {
                    init_pair(1, x, COLOR_BLACK);
                    wattron(this->win, COLOR_PAIR(1));
                }

                mvwprintw(this->win, 0, 0, this->animation[x].c_str()); // print all frame
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
