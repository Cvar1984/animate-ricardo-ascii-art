/**
 * Copyright (c) 2020 Ramdhan Firmansyah
 * File              : animate.cpp
 * Author            : Cvar1984 <gedzsarjuncomuniti@gmail.com>
 * Date              : 30.04.2020
 * Last Modified Date: 30.04.2020
 * Last Modified By  : Cvar1984 <gedzsarjuncomuniti@gmail.com>
 */

#include <iostream>
#include "src/Animate.cpp"

using std::cerr;
using std::endl;

int main(void)
{

    Animation app(0, 0, 0, 0); // full size

    vector<string> listFiles;
    string path;

    for(int x = 0; x < 153; x++) {
        path = "assets/text/ricardo_";
        path.append(std::to_string(x));
        path.append(".txt");
        listFiles.push_back(path);
    }

    if(app.generateFrame(listFiles)) {
        while(true) {
            app.play(80000); // speed in ms
        }
    }
    else {
        cerr << "Cannot generate frame, file missing" << endl;
        return -1;
    }
    return 0;
}
