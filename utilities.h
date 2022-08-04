#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>

class Utilities {
public:
    static std::vector<std::string> splitString(std::string str, char separator);
    static std::vector<int>* convertStringsToIntegers(std::string str, char separator);
};

#endif