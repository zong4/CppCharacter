// g++ std/cpp20/ranges.cpp -std=c++20

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};

    {
        auto squared_nums = nums | std::views::transform([](int i) { return i * i; }); // lazy

        // print square
        for (auto i : squared_nums)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    {
        std::for_each(nums.begin(), nums.end(), [](auto&& i) { i *= i; }); // eager

        // print nums
        for (auto i : nums)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}