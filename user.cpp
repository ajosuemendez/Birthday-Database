#include "user.h"
#include <iostream>
#include <stdlib.h>
#include "utilities.h"

#define DAY_INDEX 0
#define MONTH_INDEX 1
#define YEAR_INDEX 2

User::User(std::string addresing, std::string first_name, std::string last_name, std::string birthday, int current_year) {
    this->m_first_name = first_name;
    this->m_last_name = last_name;
    this->m_addresing = addresing;
    this->m_birthday_string = birthday;
    this->m_birth_data_array = this->getBirthData();
    this->m_birth_day = this->getBirthDay();
    this->m_birth_month = this->getBirthMonth();
    this->m_birth_year = this->getBirthYear();
    this->m_age = this->calculateAge(current_year);// calculate the age based on the current year
}

void User::displayInformation() {
    std::cout << this->m_addresing << std::endl;
    std::cout << this->m_first_name << std::endl;
    std::cout << this->m_last_name << std::endl;
    std::cout << this->m_age << std::endl;
}

std::vector<int>* User::getBirthData() {
    char delimeter = '.';

    std::vector<int>* birth_data_list = Utilities::convertStringsToIntegers(this->m_birthday_string, delimeter);

    //testing the birth data list
    int expected_size_list = 3;
    bool is_size_good = this->listSizeTest(expected_size_list, birth_data_list->size());

    if (!is_size_good) {
        std::cerr << "Error when generating the birth data list" << std::endl;
        return nullptr;
    }

    return birth_data_list;
}

int* User::getBirthDay() {
    if (this->m_birth_data_array == nullptr) {
        return nullptr;
    }
    return &this->m_birth_data_array->at(DAY_INDEX);
}

int* User::getBirthMonth() {
    if (this->m_birth_data_array == nullptr) {
        return nullptr;
    }
    return &this->m_birth_data_array->at(MONTH_INDEX);
}

int* User::getBirthYear() {
    if (this->m_birth_data_array == nullptr) {
        return nullptr;
    }
    return &this->m_birth_data_array->at(YEAR_INDEX);
}

int* User::calculateAge(int current_year) {
    if (this->m_birth_year == nullptr) {
        return nullptr;
    }
    return new int(current_year - *this->m_birth_year);
}

bool* User::isUnderLimitAge() {
    if (this->m_age == nullptr) {
        return nullptr;
    }

    bool is_under_defined_age = *this->m_age < this->m_old_age_reference;

    if (is_under_defined_age) {
        return new bool(true);
    }
    return new bool(false);
}

bool* User::isRoundBirthday() {
    if (this->m_age == nullptr) {
        return nullptr;
    }

    bool is_round_birthday = *this->m_age % this->m_round_birthday_parameter == 0;

    if (is_round_birthday) {
        return new bool(true);
    }
    return new bool(false);
}

std::string User::getProperAdressing() {
    bool is_male = this->m_addresing == "Herr";
    bool is_female = this->m_addresing == "Frau";

    if (is_male) {
        return "Sehr geehrter " + this->m_addresing;
    }

    if (is_female) {
        return "Sehr geehrte " + this->m_addresing;
    }

    return "Sehr geehrte(r) Frau/Herr";
}

void User::displayCongratulations() {
    if (this->isUnderLimitAge() == nullptr || this->isRoundBirthday() == nullptr) {
        return;
    }

    bool is_young_and_has_round_birthday = *this->isUnderLimitAge() && *this->isRoundBirthday();
    bool is_young_and_has_no_round_birthday = *this->isUnderLimitAge() && !*this->isRoundBirthday();
    bool is_not_young_and_has_round_birthday = !*this->isUnderLimitAge() && *this->isRoundBirthday();
    bool is_not_young_and_has_no_round_birthday = !*this->isUnderLimitAge() && !*this->isRoundBirthday();

    int current_day = this->m_birth_data_array->at(DAY_INDEX);
    int current_month = this->m_birth_data_array->at(MONTH_INDEX);
    int current_year = this->m_birth_data_array->at(YEAR_INDEX) + *this->m_age;

    if (is_young_and_has_round_birthday) {
        std::cout << "Hallo " << this->m_first_name << "! Heute, am " << current_day << "." << current_month << "." << current_year << ", gratulieren wir herzlich zum " << *this->m_age << ". Geburtstag!" << std::endl;
        return;
    }

    if (is_young_and_has_no_round_birthday) {
        std::cout << "Hallo " << this->m_first_name << "! Herzlichen Glueckwunsch zum Geburtstag heute " << current_day << "." << current_month << "." << current_year << "!" << std::endl;
        return;
    }

    if (is_not_young_and_has_round_birthday) {
        std::cout << this->getProperAdressing() << " " << this->m_last_name << "! Heute, am " << current_day << "." << current_month << "." << current_year << ", gratulieren wir herzlich zum " << *this->m_age << ". Geburtstag!" << std::endl;
        return;
    }

    if (is_not_young_and_has_no_round_birthday) {
        std::cout << this->getProperAdressing() << " " << this->m_last_name << "! Herzlichen Glueckwunsch zum Geburtstag heute " << current_day << "." << current_month << "." << current_year << "!" << std::endl;
        return;
    }
}
;