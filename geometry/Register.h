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
    typedef std::function<bool(Item const*, Item const*)> intersection_func;

public:
    static std::map<string_pair, intersection_func> _intersectionMap;
    static uint32_t _mapCallTimes;

    static std::set<std::string> _itemClassNames;
    static uint32_t _setCallTimes;

public:
    Register(){}
    ~Register(){}

    static bool addMap(string_pair const& names, intersection_func const& func);
    static std::map<string_pair, intersection_func> const& intersectionMap() {return _intersectionMap;}
    static std::map<string_pair, intersection_func>& mutableIntersectionMap() {return _intersectionMap;}
    static void printMap(); // print map

    static bool addSet(std::string const& name);
    static std::set<std::string> const& itemClassNames() {return _itemClassNames;}
    static void printSet(); // print set
};