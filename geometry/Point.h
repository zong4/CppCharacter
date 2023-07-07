#pragma once

#include "Item.h"
#include "Register.h"

// public item
class Point : public Item
{
private:

public:
    Point()
    {
        static std::string name = typeid(*this).name();
        static bool setFlag = Register::addSet(name);
        static bool mapFlag = addMap(name);
    }
    virtual ~Point(){}

    static bool addMap(std::string const& myName);
};