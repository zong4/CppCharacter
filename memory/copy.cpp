#include <iostream>
#include <memory>
#include <vector>

class A
{
private:
    int _num = 1;

public:
    A() { std::cout << "default constructor A" << std::endl; }
    A(int num) { std::cout << "constructor A" << std::endl; }
    A(A const& other) { std::cout << "copy constructor A" << std::endl; }
    A(A&& other) { std::cout << "move constructor A" << std::endl; }
    ~A() { std::cout << "deconstructor A" << std::endl; }

    A& operator=(A const& other)
    {
        std::cout << "copy assigment A" << std::endl;
        return *this;
    }
    A& operator=(A&& other)
    {
        std::cout << "move assigment A" << std::endl;
        return *this;
    }
};

int main()
{
    std::vector<A> vec;

    vec.reserve(6);

    // test A
    std::cout << std::endl << "vec.emplace_back()" << std::endl;
    vec.emplace_back();

    std::cout << std::endl << "vec.emplace_back(0)" << std::endl;
    vec.emplace_back(0);

    // they are same, all call move, if no move constructor, it will call copy constructor
    {
        std::cout << std::endl << "vec.emplace_back(A())" << std::endl;
        vec.emplace_back(A());

        std::cout << std::endl << "vec.push_back(A())" << std::endl;
        vec.push_back(A());
    }

    {
        std::cout << std::endl << "A a" << std::endl;
        A a;

        std::cout << std::endl << "vec.emplace_back(a)" << std::endl;
        vec.emplace_back(a);

        std::cout << std::endl << "vec.push_back(a)" << std::endl;
        vec.push_back(a);
    }

    // it will call the vector reserve, can't call default constructor directly in the vector memory
    {
        std::cout << std::endl << "vec.emplace_back()" << std::endl;
        vec.emplace_back();
    }

    std::cout << std::endl << "-----------------------------------" << std::endl;

    return 0;
}

// vec.emplace_back()
// default constructor A

// vec.emplace_back(0)
// constructor A

// vec.emplace_back(A())
// default constructor A
// move constructor A
// deconstructor A

// vec.push_back(A())
// default constructor A
// move constructor A
// deconstructor A

// A a
// default constructor A

// vec.emplace_back(a)
// copy constructor A

// vec.push_back(a)
// copy constructor A
// deconstructor A

// vec.emplace_back()
// default constructor A
// copy constructor A
// copy constructor A
// copy constructor A
// copy constructor A
// copy constructor A
// copy constructor A
// deconstructor A
// deconstructor A
// deconstructor A
// deconstructor A
// deconstructor A
// deconstructor A

// -----------------------------------
// deconstructor A
// deconstructor A
// deconstructor A
// deconstructor A
// deconstructor A
// deconstructor A
// deconstructor A