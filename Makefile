CXXFLAGS =-Wall -Wextra -Werror -s -I./include
LDFLAGS =-lncurses

animate: animate.cpp

clean:
	rm -f animate
.PHONY: clean
