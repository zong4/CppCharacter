#include <iostream>

#include "callInstance1.h"
#include "callInstance2.h"

int main()
{
    // print the address of instance1
    std::cout << "instance1 address: " << &instance1 << std::endl;
    // print the address of instance2
    std::cout << "instance2 address: " << &instance2 << std::endl;

    // is they same?
    std::cout << "instance1 == instance2: " << (&instance1 == &instance2) << std::endl;

    return 0;
}