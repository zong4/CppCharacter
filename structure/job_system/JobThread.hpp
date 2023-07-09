#pragma once

#include <future>
#include <thread>

#include "JobDequeManager.hpp"

class JobThread : public Uncopyable
{
private:
    int         _jobDequeId;
    std::thread _thread;

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

            // if (JobDequeManager::instance()[_jobDequeId]->tryPop(task))
            //     pop = true;
            // else
            // {
            //     std::this_thread::yield();
            //     continue;
            // }

            task();
        }
    }
};