#include <iostream>
#include <string>

class A
{
private:
    int _num1 = 1;
    int _num2 = 1;
    int _num3 = 1;

public:
    virtual ~A() = default;
};

class B : virtual public A
{
public:
    virtual ~B() = default;
};

int main()
{
    // sizeof(std::string)
    std::cout << sizeof(std::string) << std::endl;

    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(B) << std::endl;

    A a;
    B b;

    // std::cout << b.a() << std::endl;

    return 0;
}