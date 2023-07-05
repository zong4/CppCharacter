#include <map>
#include <iostream>

int main()
{
    std::map<int, int*> m;

    int* b = m[0];

    if(b == nullptr)
        std::cout<<"b is nullptr"<<std::endl;

    return 0;
}