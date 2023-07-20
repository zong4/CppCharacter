#include <iostream>

template <typename... Args>
decltype(auto) Add(Args... args)
{
    return (args + ...);
}

int main()
{
    std::cout << Add(1, 2, 3, 4, 5) << std::endl;

    std::string str1 = "hello";
    std::string str2 = " ";
    std::string str3 = "world";
    std::cout << Add(str1, str2, str3) << std::endl;

    return 0;
}