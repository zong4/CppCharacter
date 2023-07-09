#include "ThreadPool.hpp"

ThreadPool::ThreadPool(int num)
{
    init(num);
}

ThreadPool& ThreadPool::instance(int num)
{
    static ThreadPool pool(num);
    return pool;
}

bool ThreadPool::isRunning() const
{
    return _running;
}

// std::shared_ptr<std::condition_variable_any> ThreadPool::getCond() const
// {
//     rlock lock(_mtx);
//     return _cv;
// }

void ThreadPool::terminate()
{
    _running = false;

    // _cv->notify_all();
    for (auto& thread : _threads)
    {
        thread->setRunning(false);
        thread->join();
    }
}

void ThreadPool::init(int num)
{
    _running = true;

    _threads.reserve(num);
    JobDequeManager& jobDequeManager = JobDequeManager::instance();
    for (int i = 0; i < num; ++i)
        _threads.emplace_back(std::make_unique<JobThread>(jobDequeManager.addDeque()));
}
