#pragma once

#include <stdlib.h>

// C 风格的自定义分配器
class MyRawAllocator
{
public:
    MyRawAllocator() noexcept {}

    void* allocate(std::size_t n)
    {
        std::cout << "Allocating " << n << " bytes" << std::endl;
        return ::malloc(n);
    }

    void* reallocate(void* p, std::size_t n)
    {
        std::cout << "Reallocating " << n << " bytes" << std::endl;
        return ::realloc(p, n);
    }

    void deallocate(void* p) noexcept
    {
        std::cout << "Deallocating memory" << std::endl;
        ::free(p);
    }
};

// C++ 风格的适配器类
template <typename T>
class MyAllocator
{
public:
    using value_type = T;

    MyAllocator() noexcept {}

    template <typename U>
    MyAllocator(const MyAllocator<U>&) noexcept
    {
    }

    T* allocate(std::size_t n) { return static_cast<T*>(rawAllocator.allocate(n * sizeof(T))); }

    void deallocate(T* p, std::size_t n) noexcept { rawAllocator.deallocate(p); }

    template <typename U>
    void destroy(U* p) noexcept
    {
        p->~U();
    }

private:
    MyRawAllocator rawAllocator;
};