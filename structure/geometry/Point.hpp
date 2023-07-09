#pragma once

template <typename T>
class Point
{
private:
    T x;
    T y;

public:
    Point(T x, T y) : x(x), y(y) {}

    T getX() const { return x; }

    T getY() const { return y; }
};
