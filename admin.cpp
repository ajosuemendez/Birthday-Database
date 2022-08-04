#include "admin.h"
#include <iostream>

void Admin::congratulateUsers(std::vector<User> birthday_people_list) {
    if (!birthday_people_list.empty()) {
        for (User user : birthday_people_list) {
            user.displayCongratulations();
        }
    }
    else {
        std::cout << "No Birthdays today" << std::endl;
    }
}
;