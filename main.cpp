#include "timer.h"
#include "timerLibrary.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]){
    if(checkForCMDArguments(argc) == false){
        std::cerr << "Incorrect number of inputs. Expected 2, found " << argc <<" Exiting program timer.\n";
        exit(EXIT_FAILURE);
    }

    const char* executable{argv[1]};
    
    constexpr auto numOfExecutableCalls{10};
    
    double totalRunTime{0.0};
    
    Timer programTimer{};

    callExternalExecutable(executable, programTimer, numOfExecutableCalls, totalRunTime);

    std::cout << "Program Completed. Total time elapsed: " << totalRunTime <<"\n";
    std::cout << "Average time elapsed for program: " << totalRunTime/numOfExecutableCalls <<"\n";

    return EXIT_SUCCESS;
}