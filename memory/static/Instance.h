#pragma once

class Instance
{
public:
    Instance() {}
    ~Instance() {}

    static Instance& instance() // __attribute__((always_inline))
    {
        static Instance instance;
        return instance;
    }
};