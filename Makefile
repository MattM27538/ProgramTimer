CC=g++

all: programTimer

programTimer: programTimer.cpp
	$(CC) -Wall -Werror -Wextra -Wpedantic -std=c++20 programTimer.cpp -o programTimer

clean:
	rm programTimer