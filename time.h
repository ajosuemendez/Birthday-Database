#pragma once
#ifndef TIME_H
#define TIME_H
#include <ctime>

class Time {
private:
    std::time_t m_system_time;
    std::tm* m_current_time;

public:
    Time();

public:
    int getCurrentDay();
    int getCurrentMonth();
    int getCurrentYear();
};

#endif