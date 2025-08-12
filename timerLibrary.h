#include "timer.h"

#ifndef programTimer_h
#define programTimer_h

bool checkForCMDArguments(const int argc);

void callExternalExecutable(const char* executable, Timer& programTimer, const int numOfExecutableCalls, double& totalRunTime);

#endif