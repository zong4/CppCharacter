#pragma once

#include "Event.hpp"

class Window
{
private:
    std::function<void(Event* event)> _callbackFun;

public:
    Window() = default;
    Window(std::function<void(Event* event)> callbackFun)
    {
        _callbackFun = callbackFun;
        Event::bind(_callbackFun);
    }
    ~Window() = default;
};