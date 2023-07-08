#pragma once

#include "Item.h"
#include "Register.h"

// public item
class Segment : public Item
{
public:
    Segment()
    {
        static bool setFlag = Register::addSet(typeid(*this).name());
        static bool mapFlag = addMap();
    }
    virtual ~Segment(){}

    bool addMap() override;
};