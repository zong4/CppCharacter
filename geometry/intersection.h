#pragma once

#include "Register.h"

inline bool isIntersection(Item const* item1, Item const* item2)
{
    Register::string_pair const key = std::make_pair(typeid(*item1).name(), typeid(*item2).name());

    if(Register::intersectionMap().find(key) == Register::intersectionMap().end())
        return false;

    return Register::mutableIntersectionMap()[key](item1, item2);
}