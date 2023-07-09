#pragma once

#include <condition_variable>

#include "JobDequeManager.hpp"
#include "JobThread.hpp"

class ThreadPool : public Uncopyable
{
private:
    bool                      _running = false;
    mutable std::shared_mutex _mtx;
    // std::shared_ptr<std::condition_variable_any> _cv;
    std::vector<std::unique_ptr<JobThread>> _threads;

private:
    ThreadPool(int num);

public:
    ~ThreadPool() { terminate(); }
    static ThreadPool& instance(int num);

    bool isRunning() const;
    // std::shared_ptr<std::condition_variable_any> getCond() const;

    void terminate();

private:
    void init(int num);
};