#pragma once

class A
{
public:
    int _num = 1;

    static int _constructor_num;
    static int _copy_num;
    static int _move_num;

public:
    explicit A() { ++_constructor_num; }
    explicit A(int num) : _num(num) { ++_constructor_num; }
    A(A const& other) : _num(other._num) { ++_copy_num; }
    A(A&& other) : _num(other._num) { ++_move_num; }
    ~A() {}

    A& operator=(A const& other)
    {
        _num = other._num;
        ++_copy_num;
        return *this;
    }
    A& operator=(A&& other)
    {
        _num = other._num;
        ++_move_num;
        return *this;
    }
};

int A::_constructor_num = 0;
int A::_copy_num        = 0;
int A::_move_num        = 0;