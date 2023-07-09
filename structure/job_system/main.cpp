#include <iostream>

#include "JobDequeManager.hpp"
#include "ThreadPool.hpp"

int main()
{
    ThreadPool& threadPool = ThreadPool::instance(4);

    std::cout << "test" << std::endl;

    return 0;
}