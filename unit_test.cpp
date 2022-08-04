#include "unit_test.h"
#include <iostream>
#include <typeinfo>

bool UnitTest::listSizeTest(int expected_list_size, int test_size) {
    bool is_list_size_good = expected_list_size == test_size;
    if (is_list_size_good) {
        //std::cout << "Test Passed" << std::endl; //uncomment this line for debugging
        return true;
    }
    //uncomment these lines for debugging
    //std::cout << "Test Failed" << std::endl; 
    //std::cout << "Expected List Size: " << expected_list_size << " Actual Size: "<< test_list.size() << std::endl;
    return false;
};