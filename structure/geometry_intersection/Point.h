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
        static bool setFlag = Register::addSet(typeid(*this).name());
        static bool mapFlag = addMap();
    }
    virtual ~Point(){}

    bool addMap() override;
};