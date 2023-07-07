#pragma once

#include <map>
#include <functional>
#include <string>
#include <set>

#include "Item.h"

class Register
{
public:
    typedef std::pair<std::string, std::string> string_pair;
    typedef std::function<void(Item const* item)> intersection_func;

private:
    static std::map<std::pair<std::string, std::string>, std::function<void(Item const* item)>> _intersectionMap;
    static std::set<std::string> _itemClassNames;
    static uint32_t _setCallTimes;

public:
    Register(){}
    ~Register(){}

    static bool addMap(string_pair const& names, intersection_func const& func);

    static bool addSet(std::string const& name);

    // print set
    static void printSet();
};