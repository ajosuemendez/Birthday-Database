#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include "user.h"
#include "unit_test.h"

class Database : public UnitTest {
private:
    std::vector<User> m_users_stack;
    std::string m_database_path;

public:
    Database(std::string database_path);

public:
    void initialize();
    void populateDatabase(std::string string_data);
    void addUsers(User user);
    std::string extractFileInformation(std::string db_document);
    std::vector<User> getBirthdaysUsers(int current_day, int current_month);
};

#endif