CC=g++

all: programTimer

programTimer: main.cpp timer.h timer.cpp programTimer.h programTimer.cpp
	$(CC) -Wall -Werror -Wextra -Wpedantic -std=c++20 main.cpp timer.h timer.cpp programTimer.h programTimer.cpp -o programTimer

clean:
	rm programTimer