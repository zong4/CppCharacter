#include <any>
#include <iostream>

int main()
{
    std::any any = 1.0;

    if (double d = std::any_cast<double>(any))
    {
        std::cout << d << std::endl;
    }

    return 0;
}