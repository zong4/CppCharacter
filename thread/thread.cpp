#include <chrono>
#include <iostream>
#include <thread>

int main()
{
    std::thread t1([]() { std::cout << "hello world" << std::endl; });
    t1.join();

    return 0;
}