#include "heap.hpp"

#include <iostream>

int main()
{
    // test Heap
    Heap heap(10);
    heap.push(1);
    heap.push(2);
    heap.push(3);
    heap.push(4);
    heap.push(5);
    while (!heap.empty())
    {
        std::cout << heap.pop() << std::endl;
    }
    return 0;
}