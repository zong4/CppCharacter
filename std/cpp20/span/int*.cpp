#include <iostream>
#include <span>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    // view part of arr as span from index 1 to 3
    std::span<int> span1(arr);

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

    // find the first element in span1 that is greater than 3
    auto it = std::find_if(span1.begin(), span1.end(), [](auto&& i) { return i > 3; });

    // print the element
    std::cout << *it << std::endl;

    return 0;
}
