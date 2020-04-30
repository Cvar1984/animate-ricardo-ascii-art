CXXFLAGS =-Wall -Wextra -Werror -g -I.
LDFLAGS =-lncurses
SOURCES ?=src

animate: $(SOURCES)/Animate.cpp

clean:
	rm -f animate
.PHONY: clean
