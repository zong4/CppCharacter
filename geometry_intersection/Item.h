#pragma once

#include <iostream>

// virtual class for all items
class Item
{
public:
    Item(){}
    virtual ~Item(){}

    virtual bool addMap() = 0; // register item intersection function
};

