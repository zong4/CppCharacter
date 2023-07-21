#pragma once

#include <functional>
#include <iostream>

class Event
{
private:
    int                                             _type;
    static std::vector<std::function<void(Event*)>> _callbacks;

public:
    Event(int type = -1) : _type(type) {}
    virtual ~Event() = default;

    inline int getType() const { return _type; }

    static void bind(std::function<void(Event*)> callback) { _callbacks.emplace_back(callback); }

    void notify()
    {
        for (auto&& callback : _callbacks)
            callback(this);
    }
};

class KeyEvent : public Event
{
public:
    KeyEvent(int type = 0) : Event(type) {}
    virtual ~KeyEvent() = default;
};
