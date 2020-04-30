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
        vector<string> listAnimation;
        vector<string> animation; // big data vector
    public:
        void generateList(vector<string> listAnimation)
        {
            this->listAnimation = listAnimation;
        }

        bool generateFrame()
        {
            for(int x = 0; x < (int)this->listAnimation.size(); x++) {
                ifstream file;
                file.open(this->listAnimation[x]); // open fstream listAnimation
                
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

        void play()
        {
            for(int x = 0; x < (int)this->animation.size(); x++) {
                mvprintw(0, 0, this->animation[x].c_str()); // print all frame
                refresh(); // refresh screen
                usleep(100000);
                clear(); // clear screen
            }
        }
};
