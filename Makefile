CC=g++

all: programTimer

programTimer: main.cpp timer.h timer.cpp timerLibrary.h timerLibrary.cpp
	$(CC) -Wall -Werror -Wextra -Wpedantic -std=c++20 main.cpp timer.h timer.cpp timerLibrary.h timerLibrary.cpp -o programTimer

clean:
	rm programTimer