#pragma once

#include "Window.hpp"

class Application
{
private:
    Window* _window;

public:
    Application()
    {
        _window = new Window([this](Event* event) { onEvent(event); });
    }
    ~Application() { delete _window; }

    void onEvent(Event* event)
    {
        std::cout << "Event type: " << event->getType() << std::endl;
        std::cout << "Application onEvent" << std::endl;
    }
};