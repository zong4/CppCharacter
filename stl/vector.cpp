#include <vector>
#include <cstdio>

int main()
{
    std::vector<std::vector<int>> vec;
    vec.emplace_back(std::vector{1, 2, 3});

    for(auto& v : vec)
        for(auto& i : v)
            printf("%d\n", i);

    return 0;
}