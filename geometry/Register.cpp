#include "Register.h"

std::map<Register::string_pair, Register::intersection_func> Register::_intersectionMap = {};
uint32_t Register::_mapCallTimes = 0;

std::set<std::string> Register::_itemClassNames = {};
uint32_t Register::_setCallTimes = 0;

bool Register::addMap(string_pair const& names, intersection_func const& func)
{
    ++_mapCallTimes; // one more function, one call

    // already had
    if(_intersectionMap.find(names) != _intersectionMap.end())
        return false;
    
    _intersectionMap[names] = func;
    return true;
}

void Register::printMap()
{
    std::cout<<"_intersectionMap: "<<std::endl;
    std::cout<<"_mapCallTimes = "<<_mapCallTimes<<std::endl;
    
    for(auto const& item : _intersectionMap)
    {
        std::cout<<item.first.first + " intersects with " + item.first.second<<std::endl;
    }
}

bool Register::addSet(std::string const& name)
{
    ++_setCallTimes; // one drived class, one call

    // already had
    if(_itemClassNames.find(name) != _itemClassNames.end())
        return false;

    _itemClassNames.insert(name);
    return true;
}

void Register::printSet()
{
    std::cout<<"_itemClassNames: "<<std::endl;
    std::cout<<"_setCallTimes = "<<_setCallTimes<<std::endl;

    for(auto const& item : _itemClassNames)
    {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
}