#include <map>
#include <iostream>

int main()
{
    std::map<int, int*> m;

    int* b = m[0];

    if(b == nullptr)
        std::cout<<"b is nullptr"<<std::endl;

    // print map.size()
    std::cout<<"map.size() = "<<m.size()<<std::endl;

    // let map[0] = b
    m[0] = b;

    // print map.size()
    std::cout<<"map.size() = "<<m.size()<<std::endl;

    return 0;
}