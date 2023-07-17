#include <iostream>
#include <memory>
#include <vector>

class A
{
public:
    int _val = 1;

public:
    A() { std::cout << "A()" << std::endl; }
    A(const A&) = delete;
    A(A&&)      = delete;
    ~A() { std::cout << "~A()" << std::endl; }

    A& operator=(const A&) = delete;
    A& operator=(A&&)      = delete;
};

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

    // shared pointer
    {
        std::shared_ptr<int> p6(new int(20));
        std::shared_ptr<int> p7 = std::move(p6);
        // std::cout << *p6 << std::endl; // change ownership
        std::cout << *p7 << std::endl;
    }

    // class A
    {
        A a1;
        // A a2 = std::move(a1);
    }

    // vector
    {
        std::vector<int*> v1{new int(1), new int(2), new int(3)};
        std::vector<int*> v2 = std::move(v1);
        // std::cout << *v1[0] << std::endl; // change ownership
        std::cout << *v2[0] << std::endl;
    }

    return 0;
}