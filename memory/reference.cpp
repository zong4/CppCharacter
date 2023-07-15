#include <iostream>

int add(int& a, int& b)
{
    a = 3;
    return a + b;
}

void call_add()
{
    int a = 1;
    int b = 2;
    std::cout << add(a, b) << std::endl;
}

int main()
{
    call_add();
    return 0;
}