#include <chrono>

#ifndef Timer_H
#define Timer_H

class Timer{
    public:
        void reset();

        double elapsed() const;

    private:
        using Clock=std::chrono::steady_clock;
        using Second=std::chrono::duration<double, std::ratio<1>>;
        
        std::chrono::time_point<Clock> m_startTime{Clock::now()};
};

#endif

