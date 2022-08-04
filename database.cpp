#include "database.h"
#include "utilities.h"
#include "time.h"
#include <fstream>
#include <iostream>


#define ADDRESSING_INDEX 0
#define FIRST_NAME_INDEX 1
#define LAST_NAME_INDEX 2
#define BIRTHYEAR_INDEX 3

const int ADDRESING_INDEX = 0;

Database::Database(std::string database_path) {
    this->m_database_path = database_path;
}

void Database::initialize() {
    std::string raw_data = this->extractFileInformation(this->m_database_path);
    this->populateDatabase(raw_data);
}

void Database::addUsers(User user) {
    this->m_users_stack.push_back(user);
}

std::vector<User> Database::getBirthdaysUsers(int current_day, int current_month) {
    std::vector<User> birthday_people;
    for (User user : this->m_users_stack) {
        bool is_user_day_of_birth = *user.getBirthDay() == current_day;
        bool is_user_month_of_birth = *user.getBirthMonth() == current_month;
        bool is_user_birthday = is_user_day_of_birth && is_user_month_of_birth;

        if (is_user_birthday) {
            birthday_people.push_back(user);
        }
    }
    return birthday_people;
}

std::string Database::extractFileInformation(const std::string database_path) {
    std::ifstream input_file(database_path);
    if (!input_file.is_open()) {
        std::cerr << "problem while opening the file '" << database_path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

void Database::populateDatabase(std::string string_data) {
    Time local_time = Time(); //when constructing our users we need to provide the current year
    char delimeter = '\n';

    //Parse the information to generate a list of all the people
    std::vector<std::string> people_data_list = Utilities::splitString(string_data, delimeter);
    std::vector<std::string> person_data_list;

    for (std::string person : people_data_list) {
        //Parse the personal data for each Person
        person_data_list = Utilities::splitString(person, '\t');

        //we use the inherite unit test funtion
        int expected_size = 4;
        bool is_correct_list_size = this->listSizeTest(expected_size, person_data_list.size()); //we expect to have 4 attributes for each person

        if (!is_correct_list_size) {
            std::cout << "Error when constructing user" << std::endl;
            return;
        }

        //bool is_type_int = this->isTypeInt()

       //Start building our database entity based on users information
        this->addUsers(User(person_data_list.at(ADDRESSING_INDEX),
            person_data_list.at(FIRST_NAME_INDEX),
            person_data_list.at(LAST_NAME_INDEX),
            person_data_list.at(BIRTHYEAR_INDEX),
            local_time.getCurrentYear()));

        person_data_list.clear();
    }
}
;
