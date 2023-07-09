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
    rlock lock(_mtx);
    return _running;
}

// std::shared_ptr<std::condition_variable_any> ThreadPool::getCond() const
// {
//     rlock lock(_mtx);
//     return _cv;
// }

void ThreadPool::terminate()
{
    {
        wlock lock(_mtx);
        if (_running)
            _running = false;
        else
            return;
    }

    // _cv->notify_all();
    for (auto& thread : _threads)
        thread->join();
}

void ThreadPool::init(int num)
{
    _running = true;

    _threads.reserve(num);
    for (int i = 0; i < num; ++i)
        _threads.emplace_back(std::make_unique<JobThread>(JobDequeManager::instance().add()));
}
