#include "Register.h"

std::map<std::pair<std::string, std::string>, std::function<void(Item const* item)>> Register::_intersectionMap = {};
std::set<std::string> Register::_itemClassNames = {};
uint32_t Register::_setCallTimes = 0;

bool Register::addMap(string_pair const& names, intersection_func const& func)
{
    // already had
    if(_intersectionMap.find(names) != _intersectionMap.end())
        return false;
    
    _intersectionMap[names] = func;
    return true;
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
    std::cout<<"_setCallTimes = "<<_setCallTimes<<std::endl;

    std::cout<<"_itemClassNames = ";
    for(auto const& item : _itemClassNames)
    {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
}