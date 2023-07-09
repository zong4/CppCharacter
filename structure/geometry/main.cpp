#include <iostream>

#include "Segment.hpp"

int main()
{
    Point<int> p1(1, 2);
    Point<int> p2(3, 4);

    Segment<Point<int>> s(p1, p2);

    std::cout << s.getLength() << std::endl;

    return 0;
}