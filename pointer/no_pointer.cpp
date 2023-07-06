#include <iostream>

class Base
{
public:
    Base() {}

    void Destroy()
    {
        delete this;
    }

private:
    virtual ~Base() // can't called by system
    {
        std::cout<<"Base destructor"<<std::endl;
    }
};

class ProtectedBase
{
public:
    ProtectedBase() {}

    void Destroy()
    {
        delete this;
    }

protected:
    virtual ~ProtectedBase() // can't called by system
    {
        std::cout<<"ProtectedBase destructor"<<std::endl;
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
    ProtectedDerived() {}
    ~ProtectedDerived() 
    {
        std::cout<<"ProtectedDerived destructor"<<std::endl;
    }
};

int main()
{
    {
        std::cout<<"Test Base"<<std::endl;
        Base* b = new Base();
        std::cout<<"b is "<<b<<std::endl;
    }

    {
        std::cout<<"Test ProtectedBase"<<std::endl;
        ProtectedBase* b = new ProtectedBase();
        std::cout<<"b is "<<b<<std::endl;
    }

    {
        std::cout<<"Test ProtectedDerived"<<std::endl;
        ProtectedDerived* b = new ProtectedDerived();
        delete b;
        std::cout<<"b is "<<b<<std::endl;
    }

    return 0;
}