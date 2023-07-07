#pragma once

#include "Item.h"
#include "Register.h"

// public item
class Segment : public Item
{
public:
    Segment()
    {
        static bool flag = Register::addSet("Segment");
    }
    virtual ~Segment(){}
};