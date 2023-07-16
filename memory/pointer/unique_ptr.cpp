#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> p1(new int(10));
    // std::unique_ptr<int> p2 = p1; // error, can't copy unique_ptr
    std::unique_ptr<int> p3 = std::move(p1); // ok, p3 is now the owner of the memory
    // std::cout << *p1 << std::endl;
    std::cout << *p3 << std::endl;

    return 0;
}