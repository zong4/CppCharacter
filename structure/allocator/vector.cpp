#include <algorithm>
#include <iostream>
#include <vector>

#include "A.hpp"
#include "Allocator.hpp"

int size     = 10;
int capacity = 11;

int main()
{
    std::cout << std::endl << "c++ style" << std::endl << std::endl;

    // c++ style
    std::vector<A> vec;
    {
        vec.reserve(capacity);

        for (int i = 0; i < size; ++i)
            vec.emplace_back(i);

        vec.shrink_to_fit();

        // std::partition(vec.begin(), vec.end(), [](A const& a) { return a._num % 2 == 0; });
        // vec.resize(5);

        std::cout << "A constructor num: " << A::_constructor_num << std::endl;
        std::cout << "A copy num: " << A::_copy_num << std::endl;
        std::cout << "A move num: " << A::_move_num << std::endl;
    }

    std::cout << std::endl << "c style" << std::endl << std::endl;

    // c style
    A* arr;
    {
        // malloc
        arr = (A*)malloc(sizeof(A) * capacity);

        // placement new
        for (int i = 0; i < size; ++i)
            new (arr + i) A(i);

        // realloc
        arr = (A*)realloc(arr, sizeof(A) * (capacity + 1));

        std::cout << "A constructor num: " << A::_constructor_num << std::endl;
        std::cout << "A copy num: " << A::_copy_num << std::endl;
        std::cout << "A move num: " << A::_move_num << std::endl;
    }

    // compare vec and arr
    bool is_same = true;
    for (int i = 0; i < size; ++i)
    {
        if (vec[i]._num != arr[i]._num)
            is_same = false;
    }

    std::cout << std::endl;
    if (is_same)
        std::cout << "vec == arr" << std::endl;
    else
        std::cout << "vec != arr" << std::endl;

    return 0;
}