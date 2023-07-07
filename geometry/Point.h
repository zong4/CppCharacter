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

    static bool addMap()
    {
        // for(auto const& Register::_itemClassNames)
        // {
        //     Register::addMap(std::make_pair("Point", item), [](Item const* item)
        //     {
        //         std::cout<<"Point::lookup()"<<std::endl;
        //     });
        // }

        return true;
    }
};