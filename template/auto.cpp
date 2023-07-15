#include <iostream>
#include <string>
#include <typeinfo>
#include <utility>

template <typename T>
decltype(auto) DeliverT(T& param)
{
    std::cout << typeid(T).name() << std::endl;
    std::cout << typeid(param).name() << std::endl;

    return param[0];
}

template <typename T>
void DeliverTRef1(T& param)
{
    param = "123";

    std::cout << typeid(T).name() << std::endl;
    std::cout << typeid(param).name() << std::endl;
}

template <typename T>
decltype(auto) DeliverTRef2(T&& param)
{
    std::cout << typeid(T).name() << std::endl;
    std::cout << typeid(param).name() << std::endl;

    // return std::forward<T>(param)[0]; // which return type?
    return param[0];
}

int main()
{
    // const char* const name1 = "Hello1";
    // DeliverT(name1);    // const char*, no const
    // DeliverTRef1(name1); // const char* const&, can't pointer to another string

    {
        std::string name2 = "Hello2";
        DeliverTRef1(name2); // std::string &
        DeliverT(name2) = 'W';
        std::cout << name2 << std::endl;
    }

    {
        // left refference
        std::string name3   = "Hello3";
        DeliverTRef2(name3) = 'W';
        std::cout << name3 << std::endl;

        // right refference
        DeliverTRef2(std::string("Hello4")) = 'W';
    }

    return 0;
}