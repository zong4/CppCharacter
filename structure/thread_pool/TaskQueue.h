#pragma once

#include <mutex>
#include <queue>
#include <shared_mutex>

using wlock = std::unique_lock<std::shared_mutex>;
using rlock = std::shared_lock<std::shared_mutex>;

template <typename T>
class TaskQueue : protected std::queue<T>
{
private:
    mutable std::shared_mutex _mtx;

public:
    TaskQueue() = default;
    ~TaskQueue() { clear(); }
    TaskQueue(TaskQueue const&)            = delete;
    TaskQueue(TaskQueue&&)                 = delete;
    TaskQueue& operator=(TaskQueue const&) = delete;
    TaskQueue& operator=(TaskQueue&&)      = delete;

    size_t size() const;
    bool   empty() const;

    void clear()
    {
        wlock lock(_mtx);
        while (!std::queue<T>::empty())
            std::queue<T>::pop();
    }

    void push(T const& obj);

    // different from std::queue::pop()
    bool pop(T& holder)
    {
        wlock lock(_mtx);

        if (std::queue<T>::empty())
            return false;

        holder = std::move(std::queue<T>::front());
        std::queue<T>::pop();
        return true;
    }

    template <typename... Args>
    void emplace(Args&&... args)
    {
        wlock lock(_mtx);
        std::queue<T>::emplace(std::forward<Args>(args)...);
    }
};