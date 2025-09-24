CC=g++

all: testSuite

testSuite : mainTest.cpp
	$(CC) ../googleTest/testSuite.o ../timerLibrary.h ../timerLibrary.cpp -o testSuite -L../../googletest/build/lib/ -lgtest -lgtest_main -pthread

# $(CC) ../programTimer.o ../googleTest/testSuite.o ../timerLibrary.h -o testSuite -L../../googletest/build/lib/ -lgtest -lgtest_main -pthread

clean : rm testSuite