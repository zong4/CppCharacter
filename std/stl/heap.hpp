#pragma once

#include <algorithm>

using namespace std;

class Heap
{
private:
    int  capacity;
    int  _size;
    int *data;

public:
    Heap(int capacity);
    ~Heap();
    void push(int value);
    int  pop();
    int  top();
    int  size() const { return _size; }
    bool empty();
};

// defination
Heap::Heap(int capacity)
{
    this->capacity = capacity;
    _size          = 0;
    this->data     = new int[capacity];
}

Heap::~Heap()
{
    delete[] this->data;
}

void Heap::push(int value)
{
    if (_size >= this->capacity)
    {
        return;
    }
    this->data[_size] = value;
    _size++;
    int index = _size - 1;
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (this->data[parent] < this->data[index])
        {
            swap(this->data[parent], this->data[index]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

int Heap::pop()
{
    if (_size <= 0)
    {
        return -1;
    }
    int value     = this->data[0];
    this->data[0] = this->data[_size - 1];
    _size--;
    int index = 0;
    while (index < _size)
    {
        int left  = index * 2 + 1;
        int right = index * 2 + 2;
        if (left >= _size)
        {
            break;
        }
        int maxIndex = left;
        if (right<_size &&this->data[right]> this->data[left])
        {
            maxIndex = right;
        }
        if (this->data[index] < this->data[maxIndex])
        {
            swap(this->data[index], this->data[maxIndex]);
            index = maxIndex;
        }
        else
        {
            break;
        }
    }
    return value;
}

int Heap::top()
{
    if (_size <= 0)
    {
        return -1;
    }
    return this->data[0];
}

bool Heap::empty()
{
    return _size == 0;
}