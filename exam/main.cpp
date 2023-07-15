#include <iostream>

int main()
{
    int c = 3;

    const int* a = &c;
    int* const b = &c;

    int d = 4;

    a = &d;
    b = &d;

    std::cout << *a << std::endl;
    std::cout << *b << std::endl;

    return 0;
}