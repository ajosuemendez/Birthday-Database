#include "user.h"
#include "database.h"
#include "time.h"
#include "admin.h"

int main() {
    Time local_time = Time();

    Database db("./geburtstage.txt"); // we give the path of our database
    db.initialize();

    std::vector<User> birthday_people_list = db.getBirthdaysUsers(local_time.getCurrentDay(), local_time.getCurrentMonth());

    Admin::congratulateUsers(birthday_people_list);

    return 0;
}