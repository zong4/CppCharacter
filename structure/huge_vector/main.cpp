#include <algorithm>
#include <iostream>
#include <ranges>
#include <span>
#include <vector>

#include "A.hpp"

#define PRINT
#include "HugeVector.hpp"

constexpr size_t size     = 1;
constexpr size_t capacity = 3;

int main()
{
    // c++ style
    std::cout << std::endl << "c++ style" << std::endl << std::endl;
    {
        std::vector<A> vec;

        std::cout << std::endl << "reserve(size)" << std::endl;

        vec.reserve(size);
        for (int i = 0; i < size; ++i)
            vec.emplace_back(i);

        std::cout << std::endl << "reserve(capacity)" << std::endl;

        vec.reserve(capacity);
        for (int i = size; i < capacity; ++i)
            vec.emplace_back(i);

        // std::cout << "A constructor num: " << A::_constructor_num << std::endl;
        // std::cout << "A copy num: " << A::_copy_num << std::endl;
        // std::cout << "A move num: " << A::_move_num << std::endl;

        std::cout << std::endl << "end" << std::endl;
    }

    // self vector
    std::cout << std::endl << "self vector" << std::endl << std::endl;
    {
        HugeVector<A> vec;

        std::cout << std::endl << "reserve(size)" << std::endl;

        vec.reserve(size);
        for (int i = 0; i < size; ++i)
            vec.emplace_back(i);

        std::cout << std::endl << "reserve(capacity)" << std::endl;

        vec.reserve(capacity);
        for (int i = size; i < capacity; ++i)
            vec.emplace_back(i);

        // scan
        {
            std::cout << std::endl << "scan print" << std::endl;

            std::span<A> span(vec.begin(), vec.size());

            auto span_ranges = span | std::views::all;
            std::ranges::for_each(span_ranges, [](auto&& i) { std::cout << i._num << " "; });
            std::cout << std::endl;
        }

        // stl
        {
            std::cout << std::endl << "stl print" << std::endl;

            std::for_each(vec.begin(), vec.end(), [](auto&& i) { std::cout << i._num << " "; });
            std::cout << std::endl;
        }

        // std::cout << "A constructor num: " << A::_constructor_num << std::endl;
        // std::cout << "A copy num: " << A::_copy_num << std::endl;
        // std::cout << "A move num: " << A::_move_num << std::endl;

        std::cout << std::endl << "end" << std::endl;
    }

    return 0;
}