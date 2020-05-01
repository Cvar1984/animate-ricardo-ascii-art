CXXFLAGS =-Wall -Wextra -Werror -s -I.
LDFLAGS =-lncurses
SOURCES ?=src

animate: $(SOURCES)/Animate.cpp

clean:
	rm -f animate
.PHONY: clean
