#include <iostream>

#include "JobDequeManager.hpp"
#include "ThreadPool.hpp"

int main()
{
    ThreadPool& threadPool = ThreadPool::instance(4);

    return 0;
}