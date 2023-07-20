
#include <iostream>

void fun1() noexcept
{
    std::cout << "fun1" << std::endl;
}

void fun2(bool noexcept_flag = true)
{
    if (!noexcept_flag)
        throw std::exception();

    std::cout << "fun2" << std::endl;
}

int main()
{
    bool fun1_nonexcept = noexcept(fun1());
    std::cout << "fun1_nonexcept: " << fun1_nonexcept << std::endl;

    bool fun2_nonexcept1 = noexcept(fun2());
    std::cout << "fun2_nonexcept1: " << fun2_nonexcept1 << std::endl;

    bool fun2_nonexcept2 = noexcept(fun2(false));
    std::cout << "fun2_nonexcept2: " << fun2_nonexcept2 << std::endl;

    return 0;
}