#include "timer.h"
#include <iostream>
#include <chrono>
#include <cstdlib>

bool checkForCMDArguments(const int argc){
    if(argc == 2){
        return true;
    }

    return false;
}

void callExternalExecutable(const char* executable, Timer& programTimer, const int numOfExecutableCalls, double& totalRunTime){
    constexpr auto systemCallSuccess{0};

    for(int i{0}; i<numOfExecutableCalls; ++i){
        if(system(executable) != systemCallSuccess){
            std::cerr << "System call failed. Exiting program timer.\n";
            exit(EXIT_FAILURE);
        };

        totalRunTime+=programTimer.elapsed();

        programTimer.reset();
    }

    return;
}