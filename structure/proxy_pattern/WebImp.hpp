#pragma once

#include <iostream>

template <class T>
class WebImp
{
public:
    void request() { static_cast<T*>(this)->request(); }
};