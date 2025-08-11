#include <iostream>
#include <chrono>
#include <cstdlib>

class Timer{
    public:
        void reset(){
            m_startTime=Clock::now();
        }

        double elapsed() const{
            return std::chrono::duration_cast<Second>(Clock::now() - m_startTime).count();
        }


    private:
        using Clock=std::chrono::steady_clock;
        using Second=std::chrono::duration<double, std::ratio<1>>;
        
        std::chrono::time_point<Clock> m_startTime{Clock::now()};
};

void checkForCMDarguments(const int argc){
    if(argc != 2){
        std::cerr << "Incorrect number of inputs. Expected 2, found " << argc <<" Exiting program timer.\n";
        exit(EXIT_FAILURE);
    }

    return;
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



int main(int argc, char* argv[]){
    checkForCMDarguments(argc);

    const char* executable{argv[1]};
    
    constexpr auto numOfExecutableCalls{10};
    
    double totalRunTime{0.0};
    
    Timer programTimer{};

    callExternalExecutable(executable, programTimer, numOfExecutableCalls, totalRunTime);

    std::cout << "Program Completed. Total time elapsed: " << totalRunTime <<"\n";
    std::cout << "Average time elapsed for program: " << totalRunTime/numOfExecutableCalls <<"\n";

    return EXIT_SUCCESS;
}