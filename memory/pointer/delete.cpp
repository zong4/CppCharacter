#include <vector>
#include <cstdio>

int main()
{
    std::vector<int*> vec1;
    std::vector<int*> vec2;

    for(int i = 0; i < 10; i++)
    {
        int* p = new int(i);
        vec1.push_back(p);
        vec2.push_back(p);
    }

    // delete 
    for(auto& p : vec1)
        delete p;

    // clear vec1
    vec1.clear();

    // clear vec2
    vec2.clear();
    
    // print
    for(auto& p : vec1)
        printf("%d\n", *p);

    // print vec2
    for(auto& p : vec2)
        printf("%d\n", *p);

    return 0;
}