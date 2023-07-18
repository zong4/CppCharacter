#include <unistd.h>

#include <iostream>
#include <vector>

#include "Allocator.hpp"

int main()
{
    std::vector<int, MyAllocator<int>> v(0);

    for (size_t i = 0; i < 30; i++)
    {
        v.push_back(i);
    }
}