#include "TaskQueue.h"

template <typename T>
size_t TaskQueue<T>::size() const
{
    rlock lock(_mtx);
    return std::queue<T>::size();
}

template <typename T>
bool TaskQueue<T>::empty() const
{
    rlock lock(_mtx);
    return std::queue<T>::empty();
}

template <typename T>
void TaskQueue<T>::push(T const& obj)
{
    wlock lock(_mtx);
    std::queue<T>::push(obj);
}
