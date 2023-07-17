#include <iostream>
#include <memory>

int main()
{
    // unique pointer
    {
        std::unique_ptr<int> p1(new int(5));

        // std::unique_ptr<int> p2 = p1; // error, can't copy unique_ptr
        std::unique_ptr<int> p3 = std::move(p1); // ok, p3 is now the owner of the memory

        // std::cout << *p1 << std::endl;
        std::cout << *p3 << std::endl;

        auto fun = [p3 = std::move(p3)]() { std::cout << *p3 << std::endl; };
        fun();
        // std::cout << *p3 << std::endl; // unqiue_ptr isn't move back
    }

    // raw pointer
    {
        int* p4 = new int(10);
        int* p5 = std::move(p4); // equal to p5 = p4
        std::cout << *p4 << std::endl;
    }

    return 0;
}