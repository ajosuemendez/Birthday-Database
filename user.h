#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "unit_test.h"

class User : public UnitTest {
private:
    const int m_old_age_reference = 50;
    const int m_round_birthday_parameter = 10;

protected:
    std::string m_first_name;
    std::string m_last_name;
    std::string m_addresing;
    std::string m_birthday_string;
    int* m_birth_day;
    int* m_birth_month;
    int* m_birth_year;
    int* m_age;
    std::vector<int>* m_birth_data_array;

public:
    User(std::string addresing, std::string first_name,
        std::string last_name, std::string birthday,
        int current_year);

public:
    std::vector<int>* getBirthData();
    int* getBirthYear();
    int* getBirthMonth();
    int* getBirthDay();
    int* calculateAge(int current_year);
    bool* isUnderLimitAge();
    bool* isRoundBirthday();
    void displayCongratulations();
    void displayInformation();
    std::string getProperAdressing();
};

#endif

