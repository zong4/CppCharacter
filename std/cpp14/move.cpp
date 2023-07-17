#include <iostream>

void Add(const int&& a, const int&& b)
{
    std::cout << a + b << std::endl;
}

int main()
{
    const int a = 1;
    const int b = 2;
    Add(std::move(a), std::move(b));

    return 0;
}