#pragma once

#include <iostream>

// virtual class for all items
class Item
{
public:
    Item(){}
    virtual ~Item(){}

    void lookup(Item const& item)
    {
        // print typeid_item.name()
        std::cout<<"typeid_item.name() = "<<typeid(item).name()<<std::endl;
    }
};

