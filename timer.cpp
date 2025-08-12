#include "timer.h"
#include <chrono>

void Timer::reset(){
    m_startTime=Clock::now();
}

double Timer::elapsed() const{
    return std::chrono::duration_cast<Second>(Clock::now() - m_startTime).count();
}