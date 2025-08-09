#include <iostream>
#include <chrono>
#include <cstdlib> //for system()
#include <unistd.h> //delete after removing sleep()/need for exec?

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
        std::cerr << "Incorrect number of inputs. Expected 2, found " << argc <<"\n";
        exit(EXIT_FAILURE);
    }

    return;
}

int main(int argc, char* argv[]){
    checkForCMDarguments(argc);

    Timer programTimer{};

    //Create function for system call.
    constexpr auto systemCallSuccess{0};

    // if(system("./sleepTest") != systemCallSuccess){
    if(system(argv[1]) != systemCallSuccess){
        std::cerr << "system call failed. Exiting program timer.\n";
        exit(EXIT_FAILURE);
    };

    std::cout << "Program Completed time elapsed: " << programTimer.elapsed() <<"\n";

    return EXIT_SUCCESS;
}