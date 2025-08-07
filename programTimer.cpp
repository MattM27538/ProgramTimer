#include <chrono>
#include <thread>
#include <unistd.h> //delete after removing sleep()

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

//Should return runtime of program.
void timeProgram(){
    sleep(2);
}

int main(){
    std::thread timeProgramThread(timeProgram);

    timeProgramThread.join();

    return 0;
}