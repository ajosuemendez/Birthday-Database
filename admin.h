#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include <vector>
#include "user.h"

class Admin {
public:
    static void congratulateUsers(std::vector<User> birthday_people_list);
};
#endif