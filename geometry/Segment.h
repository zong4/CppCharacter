#pragma once

#include "Item.h"
#include "Register.h"

// public item
class Segment : public Item
{
public:
    Segment()
    {
        static std::string name = typeid(*this).name();
        static bool setFlag = Register::addSet(name);
        static bool mapFlag = addMap(name);
    }
    virtual ~Segment(){}

    static bool addMap(std::string const& myName);
};