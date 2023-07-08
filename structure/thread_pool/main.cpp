#include <iostream>

#include "ThreadPool.h"

int main()
{
    // ThreadPool pool = ThreadPool::instance(); // error, can't copy
    ThreadPool& pool = ThreadPool::instance();

    // print pool status
    // std::cout << "pool is running: " << pool.isRunning() << std::endl;

    {
        std::vector<std::future<int>>  int_futs;
        std::vector<std::future<bool>> bool_futs;

        // for (int i = 0; i != 30; ++i)
        // {
        //     int_futs.emplace_back(pool.async([](int i) -> int { return i; }, i));
        // }

        // for (int i = 0; i != 30; ++i)
        // {
        //     bool_futs.emplace_back(pool.async([](int i) -> bool { return i % 2 == 0; }, i));
        // }

        // for (int i = 0; i != 30; ++i)
        // {
        //     int_futs[i].get() == i;
        //     bool_futs[i].get() == (i % 2 == 0);
        // }
    }

    return 0;
}