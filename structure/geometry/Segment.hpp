#pragma once

#include <cmath>
#include <type_traits>

#include "Point.hpp"

template <typename PointT>
class Segment
{
private:
    using value_type = typename std::decay<decltype(std::declval<PointT>().getX())>::type;

    PointT start;
    PointT end;

public:
    Segment(const PointT& start, const PointT& end) : start(start), end(end) {}

    using PointValueType = value_type;

    const PointT& getStart() const { return start; }

    const PointT& getEnd() const { return end; }

    inline value_type getLength() const
    {
        return std::sqrt(std::pow(end.getX() - start.getX(), 2) + std::pow(end.getY() - start.getY(), 2));
    }
};
