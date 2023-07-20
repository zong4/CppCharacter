#include <iostream>
#include <span>
#include <vector>

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};

    // view part of arr as span from index 1 to 3
    std::span<int> span1(arr.begin() + 1, 3);

    // print span1
    for (auto& i : span1)
        std::cout << i << " ";
    std::cout << std::endl;

    std::for_each(span1.begin(), span1.end(), [](auto&& i) { i *= 2; });

    // print span1
    for (auto& i : span1)
        std::cout << i << " ";
    std::cout << std::endl;

    // print arr
    for (auto& i : arr)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}