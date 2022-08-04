#include "utilities.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>

std::vector<std::string> Utilities::splitString(std::string text, char separator) {
    std::stringstream ss_line(text);
    std::string string_element;
    std::vector<std::string> parsed_string_list;

    while (getline(ss_line, string_element, separator)) {
        parsed_string_list.push_back(string_element);
    }
    return parsed_string_list;
}

std::vector<int>* Utilities::convertStringsToIntegers(std::string text, char separator) {
    std::stringstream ss_line(text);
    std::string string_element;
    std::vector<int> integer_list;

    while (getline(ss_line, string_element, separator)) {
        try
        {
            integer_list.push_back(stoi(string_element));
        }
        catch (const std::exception& e)
        {
            std::cout << "Error while converting String to Int: ";
            std::cerr << e.what() << '\n';
            return nullptr;
        }
    }
    return new std::vector<int>(integer_list);
};