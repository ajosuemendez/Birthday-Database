#include "time.h"

Time::Time() {
    this->m_system_time = std::time(nullptr);
    this->m_current_time = std::localtime(&m_system_time);
}

int Time::getCurrentDay() {
    return this->m_current_time->tm_mday;
}

int Time::getCurrentMonth() {
    return this->m_current_time->tm_mon + 1; //January is return as a 0 value so we add 1
}

int Time::getCurrentYear() {
    return this->m_current_time->tm_year + 1900; //There is an offset of 1900 years
}
;