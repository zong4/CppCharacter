#include <iostream>

template<typename T1, typename T2>
auto max1(T1 a, T2 b) -> typename std::decay<decltype(true?a:b)>::type
{
    return a > b ? a : b;
}

template<typename T1, typename T2>
auto max2(T1 a, T2 b) -> decltype(true ? a : b)
{
    return a > b ? a : b;
}

int main()
{
    int i = 10;
    int j = 15;
    int& refJ = j;

    auto a = max1(i, refJ);
    
    // cout a and it's type
    std::cout << a << std::endl;
    std::cout << typeid(a).name() << std::endl;

    auto b = max2(i, refJ);

    // cout b and it's type
    std::cout << b << std::endl;
    std::cout << typeid(b).name() << std::endl;

    return 0;
}