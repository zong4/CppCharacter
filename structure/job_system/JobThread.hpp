#pragma once

#include <future>
#include <thread>

#include "JobDeque.hpp"
#include "JobDequeManager.hpp"

class JobThread : public Uncopyable
{
private:
    std::thread _thread;
    int         _jobDequeId;

public:
    explicit JobThread(int jobDequeId) : _jobDequeId(jobDequeId) { _thread = std::thread(&JobThread::spawn, this); }
    ~JobThread() = default;

    inline void join() { _thread.join(); }

private:
    void spawn()
    {
        for (;;)
        {
            bool                  pop = false;
            std::function<void()> task;

            task();
        }
    }
};