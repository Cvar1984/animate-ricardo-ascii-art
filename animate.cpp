/**
 * Copyright (c) 2020 Ramdhan Firmansyah
 * File              : animate.cpp
 * Author            : Cvar1984 <gedzsarjuncomuniti@gmail.com>
 * Date              : 30.04.2020
 * Last Modified Date: 30.04.2020
 * Last Modified By  : Cvar1984 <gedzsarjuncomuniti@gmail.com>
 */

#include <ncurses.h>
#include <iostream>
#include <src/Animate.cpp>

using std::cerr;
using std::endl;


int main(void)
{
    initscr();
    //cbreak();
    //noecho();
    curs_set(0); // hide cursors

    Animation app;

    vector<string> listFiles;
    string path;

    for(int x = 0; x < 153; x++) {

        path = "assets/text/ricardo_";
        path.append(std::to_string(x));
        path.append(".txt");

        listFiles.push_back(path);
    }

    app.generateList(listFiles);

    if(app.generateFrame()) {
        WINDOW *win = newwin(0, 0, 0, 0); // full screen
        while(true) {
            app.play();
        }
        wrefresh(win); // refresh window
        endwin(); // close window
    }
    else {
        cerr << "Cannot generate frame, file missing" << endl;
        return -1;
    }
    return 0;
}
