#pragma once

#include <stdlib.h>

#include <limits>

template <typename T>
class RawAllocator
{
public:
    using value_type       = T;
    using pointer          = T*;
    using const_pointer    = const T*;
    using reference        = T&;
    using const_reference  = const T&;
    using rvalue_reference = T&&;

    using void_pointer       = void*;
    using const_void_pointer = const void*;

    using size_type  = size_t;
    using difference = std::ptrdiff_t;

public:
    RawAllocator() = default;

    template <typename U>
    RawAllocator(const RawAllocator<U>&) noexcept
    {
    }

    ~RawAllocator() = default;

    pointer allocate(size_type numObjects) { return static_cast<pointer>(mallocating(numObjects * sizeof(value_type))); }

    pointer reallocate(size_type numObjects, void_pointer ptr)
    {
        void_pointer vptr = reallocating(numObjects * sizeof(T), ptr);
        if (vptr)
            return static_cast<pointer>(vptr);

        return allocate(numObjects);
    }
    pointer reallocate(size_type numObjects, const_void_pointer constPtr)
    {
        return reallocate(numObjects, const_cast<void_pointer>(constPtr));
    }

    void deallocate(pointer ptr, size_type numObjects) noexcept { deallocating(ptr); }

    size_type max_size() const { return std::numeric_limits<size_type>::max(); }

    template <class U, class... Args>
    void construct(U* p, Args&&... args)
    {
        new (p) U(std::forward<Args>(args)...);
    }

    template <typename U>
    void destroy(U* p) noexcept
    {
        p->~U();
    }

    // change the class type
    template <class U>
    struct rebind
    {
        using other = RawAllocator<U>;
    };

private:
    void_pointer mallocating(size_type n)
    {
        std::cout << "allocating " << n << " bytes" << std::endl;
        return ::malloc(n);
    }

    void_pointer reallocating(size_type n, void_pointer p)
    {
        std::cout << "reallocating " << n << " bytes" << std::endl;
        return ::realloc(p, n);
    }

    void deallocating(void_pointer p) noexcept
    {
        std::cout << "deallocating memory" << std::endl;
        ::free(p);
    }
};