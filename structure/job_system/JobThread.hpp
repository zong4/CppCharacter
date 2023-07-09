#pragma once

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
        for (;;)
        {
            JobDequeManager&      jobDequeManager = JobDequeManager::instance();
            std::function<void()> task;

            {
                rlock lock(jobDequeManager._mtx);
                jobDequeManager._cv.wait(
                    lock, [this, &jobDequeManager, &task] { return !_running || jobDequeManager[_jobDequeId]->pop_front(task); });
            }

            if (!_running)
                return;

            task();
        }
    }
};