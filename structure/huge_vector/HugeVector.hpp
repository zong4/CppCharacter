#pragma once

#include "RawAllocator.hpp"

template <typename T>
class HugeVector
{
private:
    RawAllocator<T> allocator;

public:
    using value_type       = typename RawAllocator<T>::value_type;
    using pointer          = typename RawAllocator<T>::pointer;
    using const_pointer    = typename RawAllocator<T>::const_pointer;
    using reference        = typename RawAllocator<T>::reference;
    using const_reference  = typename RawAllocator<T>::const_reference;
    using rvalue_reference = typename RawAllocator<T>::rvalue_reference;

    using void_pointer       = typename RawAllocator<T>::void_pointer;
    using const_void_pointer = typename RawAllocator<T>::const_void_pointer;

    using size_type  = typename RawAllocator<T>::size_type;
    using difference = typename RawAllocator<T>::difference;

private:
    size_type _size    = 0;
    size_type _maxSize = 1;
    pointer   _data;

public:
    HugeVector() { _data = allocator.allocate(_maxSize); }
    HugeVector(size_type size) : _size(size), _maxSize(size)
    {
        _data = allocator.allocate(_maxSize);

        for (size_type i = 0; i < _size; ++i)
            allocator.construct(_data + i, value_type());
    }
    HugeVector(const HugeVector& other) : _size(other._size), _maxSize(other._maxSize)
    {
        _data = allocator.allocate(_maxSize);

        for (size_type i = 0; i < _size; ++i)
            allocator.construct(_data + i, std::move(other._data[i]));
    }
    HugeVector(HugeVector&& other) : _size(other._size), _maxSize(other._maxSize)
    {
        _data = allocator.allocate(_maxSize);

        for (size_type i = 0; i < _size; ++i)
            allocator.construct(_data + i, std::move(other._data[i]));
    }
    ~HugeVector()
    {
        for (size_type i = 0; i < _size; ++i)
            allocator.destroy(_data + i);

        allocator.deallocate(_data, _maxSize);
    }

    inline size_type     size() const { return _size; }
    inline size_type     capacity() const { return _maxSize; }
    inline const_pointer constData() const { return _data; }
    inline reference     operator[](size_type index) { return _data[index]; }

    void push_back(const_reference val)
    {
        if (_size == _maxSize)
            redistribute(_maxSize * 2);

        _data[_size++] = val;
    }

    template <typename... Args>
    void emplace_back(Args&&... args)
    {
        if (_size == _maxSize)
            redistribute(_maxSize * 2);

        allocator.construct(_data + _size, std::forward<Args>(args)...);
        ++_size;
    }

    void reserve(size_type maxSize)
    {
        if (maxSize <= _maxSize)
            return;

        size_type newSize = maxSize > _maxSize * 2 ? maxSize : _maxSize * 2;
        redistribute(newSize);
    }

private:
    void redistribute(size_type maxSize)
    {
        pointer data = allocator.reallocate(maxSize, _data);
        if (data)
        {
            _maxSize = maxSize;
            _data    = data;
            return;
        }

        data = allocator.allocate(maxSize);
        for (size_type i = 0; i < _size; ++i)
            data[i] = std::move(_data[i]);

        allocator.deallocate(_data, _maxSize);

        _maxSize = maxSize;
        _data    = data;
    }
};