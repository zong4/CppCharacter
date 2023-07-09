#pragma once

#include <future>
#include <thread>

#include "JobDequeManager.hpp"

class JobThread : public Uncopyable
{
private:
    bool        _running = true;
    int         _jobDequeId;
    std::thread _thread;

public:
    explicit JobThread(int jobDequeId) : _jobDequeId(jobDequeId) { _thread = std::thread(&JobThread::spawn, this); }
    ~JobThread() = default;

    inline void setRunning(bool running) { _running = running; }

    inline void join() { _thread.join(); }

private:
    void spawn()
    {
        while (_running)
        {
            std::function<void()> task;

            if (JobDequeManager::instance()[_jobDequeId]->pop_front(task))
                task();
            // else
            //     std::this_thread::yield();
        }
    }
};