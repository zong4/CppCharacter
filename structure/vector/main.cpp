#include <algorithm>
#include <iostream>
#include <vector>

#define PRINT
#include "A.hpp"
#include "Allocator.hpp"

int size     = 1;
int capacity = 2;

int main()
{
    // c++ style
    std::cout << std::endl << "c++ style" << std::endl << std::endl;
    {
        std::vector<A> vec;

        vec.reserve(capacity);

        for (int i = 0; i < size; ++i)
            vec.emplace_back(i);

        vec.shrink_to_fit();

        // std::partition(vec.begin(), vec.end(), [](A const& a) { return a._num % 2 == 0; });
        // vec.resize(5);

        // std::cout << "A constructor num: " << A::_constructor_num << std::endl;
        // std::cout << "A copy num: " << A::_copy_num << std::endl;
        // std::cout << "A move num: " << A::_move_num << std::endl;
    }

    // c style
    std::cout << std::endl << "c style" << std::endl << std::endl;
    {
        A* arr;

        // malloc
        arr = (A*)malloc(sizeof(A) * capacity);

        // placement new
        for (int i = 0; i < size; ++i)
            new (arr + i) A(i);

        // realloc
        arr = (A*)realloc(arr, sizeof(A) * (capacity + 1));

        // std::cout << "A constructor num: " << A::_constructor_num << std::endl;
        // std::cout << "A copy num: " << A::_copy_num << std::endl;
        // std::cout << "A move num: " << A::_move_num << std::endl;
    }

    // self allocator
    std::cout << std::endl << "self allocator" << std::endl << std::endl;
    {
        MyAllocator<A> allocator;

        A* arr = allocator.allocate(size);
        for (int i = 0; i < size; i++)
            arr[i] = A(i);

        arr = allocator.allocate(capacity, arr);
        for (int i = size; i < capacity; i++)
            arr[i] = A(i);

        for (int i = 0; i < capacity; i++)
            allocator.destroy(arr + i);

        allocator.deallocate(arr, capacity);
    }

    return 0;
}