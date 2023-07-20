#include <iostream>
#include <thread>
#include <vector>

constinit size_t thread_num = 2;

constinit thread_local size_t jobs_size = 0;

void DoJob()
{
    ++jobs_size;

    std::cout << "thread id: " << std::this_thread::get_id() << ", jobs_size: " << jobs_size << std::endl;
}

int main()
{
    std::vector<size_t> jobs_size_vec(thread_num, jobs_size);

    std::vector<std::thread> thread_vec;
    thread_vec.reserve(thread_num);

    for (size_t i = 0; i < thread_num; ++i)
        thread_vec.emplace_back(DoJob);

    for (auto&& thread : thread_vec)
        thread.join();

    for (auto&& jobs_size : jobs_size_vec)
        std::cout << jobs_size << std::endl;

    return 0;
}
