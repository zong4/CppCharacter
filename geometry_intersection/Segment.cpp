#include "Segment.h"

bool Segment::addMap()
{
    std::string myName = typeid(*this).name();

    for(auto const& name : Register::itemClassNames())
    {
        Register::addMap(std::make_pair(myName, name), [](Item const* item1, Item const* item2) -> bool
        {
            std::cout<<static_cast<std::string>(typeid(*item1).name()) + " intersects with " + static_cast<std::string>(typeid(*item2).name())<<std::endl;
            return true;
        });

        if(myName == name)
            continue;

        // reverse and add again
        Register::addMap(std::make_pair(name, myName), [](Item const* item1, Item const* item2) -> bool
        {
            std::cout<<static_cast<std::string>(typeid(*item1).name()) + " intersects with " + static_cast<std::string>(typeid(*item2).name())<<std::endl;
            return true;
        });
    }

    return true;
}
