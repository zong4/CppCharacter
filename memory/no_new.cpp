#include <iostream>
#include <memory>

class Base
{
public:
    int _val = 1;

    Base() {}

    void Destroy() { delete this; }

private:
    virtual ~Base() // can't called by system
    {
        std::cout << "Base destructor" << std::endl;
    }
};

class ProtectedBase
{
public:
    int _val = 1;

    ProtectedBase() {}

    void Destroy() { delete this; }

protected:
    virtual ~ProtectedBase() // can't called by system
    {
        std::cout << "ProtectedBase destructor" << std::endl;
    }
};

// can't inherit from Base, because Base destructor is private
// class Derived : public Base
// {
// public:
//     Derived() {}
//     ~Derived() {}
// };

class ProtectedDerived : public ProtectedBase
{
public:
    int _val = 1;

    ProtectedDerived() {}
    ~ProtectedDerived() { std::cout << "ProtectedDerived destructor" << std::endl; }
};

int main()
{
    {
        std::cout << "Test Base" << std::endl;
        // std::unique_ptr<Base> b = std::make_unique<Base>();
    }

    {
        std::cout << "Test ProtectedBase" << std::endl;

        auto destroy = [](ProtectedBase* p) { p->Destroy(); };

        std::unique_ptr<ProtectedBase, decltype(destroy)> b(new ProtectedBase(), destroy);
    }

    {
        std::cout << "Test ProtectedDerived" << std::endl;
        std::unique_ptr<ProtectedDerived> b = std::make_unique<ProtectedDerived>();
    }

    return 0;
}