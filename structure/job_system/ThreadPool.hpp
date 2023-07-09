#pragma once

#include "JobDequeManager.hpp"
#include "JobThread.hpp"

class ThreadPool : public Uncopyable
{
private:
    bool                                    _running = false;
    mutable std::shared_mutex               _mtx;
    std::vector<std::unique_ptr<JobThread>> _threads;

private:
    ThreadPool(int num);

public:
    ~ThreadPool() { terminate(); }
    static ThreadPool& instance(int num);

    bool isRunning() const;

    void terminate();

private:
    void init(int num);
};