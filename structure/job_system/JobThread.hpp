#pragma once

#include <future>
#include <thread>

#include "JobDeque.hpp"
#include "JobDequeManager.hpp"

class JobThread
{
private:
    std::thread _thread;
    uint32_t    _jobDequeId;

public:
    explicit JobThread() {}
    explicit JobThread(int jobDequeId) : _jobDequeId(jobDequeId) { _thread = std::thread(&JobThread::spawn, this); }
    ~JobThread()                           = default;
    JobThread(JobThread const&)            = delete;
    JobThread(JobThread&&)                 = delete;
    JobThread& operator=(JobThread const&) = delete;
    JobThread& operator=(JobThread&&)      = delete;

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