# animate-ricardo-ascii-art

[![CodeFactor](https://www.codefactor.io/repository/github/Cvar1984/animate-ricardo-ascii-art/badge)](https://www.codefactor.io/repository/github/cvar1984/animate-ricardo-ascii-art)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

Animate ricardo milos and other animation on your terminal
## todo
- add music on the background

![Ricardo](assets/images/ricardo.gif)

![Yuno](assets/images/yuno.gif)

```c++
#include<animate.hpp>

int main() {
    Animate app(true); // colors, height, width, sheight, swidth

    if(app.generateFrame({"frame1.txt","frame2.txt"}))
        app.play(80000) // speed in ms
    return 0;
}
```
