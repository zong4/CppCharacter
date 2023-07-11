#pragma once

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef std::chrono::microseconds time_unit;
static const std::string          time_unit_name = "microseconds";

// store all ascii char in vector
static const std::vector<char> ascii_char = []() {
    std::vector<char> result;
    for (int i = 0; i < 128; i++)
        result.push_back(i);
    return result;
}();

std::vector<std::string> SplitByStream(std::string const& str, char delimiter);
std::vector<std::string> SplitByFind(std::string const& s, std::string const& delimiter);

void TestByFile(std::string const& path);
void TestByString(std::string const& str);