#pragma once

class A
{
public:
    int _num = -1;

    static int _constructor_num;
    static int _copy_num;
    static int _move_num;

public:
    explicit A()
    {
        ++_constructor_num;

#ifdef PRINT
        std::cout << "default constructor A" << std::endl;
#endif // PRINT
    }
    explicit A(int num) : _num(num)
    {
        ++_constructor_num;

#ifdef PRINT
        std::cout << "constructor A" << std::endl;
#endif // PRINT
    }
    A(A const& other) : _num(other._num)
    {
        ++_copy_num;

#ifdef PRINT
        std::cout << "copy constructor A" << std::endl;
#endif // PRINT
    }
    A(A&& other) : _num(other._num)
    {
        ++_move_num;

#ifdef PRINT
        std::cout << "move constructor A" << std::endl;
#endif // PRINT
    }
    ~A()
    {
#ifdef PRINT
        std::cout << "deconstructor A" << std::endl;
#endif // PRINT
    }

    A& operator=(A const& other)
    {
        _num = other._num;
        ++_copy_num;

#ifdef PRINT
        std::cout << "copy constructor A" << std::endl;
#endif // PRINT

        return *this;
    }
    A& operator=(A&& other)
    {
        _num = other._num;
        ++_move_num;

#ifdef PRINT
        std::cout << "move constructor A" << std::endl;
#endif // PRINT

        return *this;
    }
};

int A::_constructor_num = 0;
int A::_copy_num        = 0;
int A::_move_num        = 0;