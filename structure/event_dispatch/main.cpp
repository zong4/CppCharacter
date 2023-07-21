#include "Application.hpp"

int main()
{
    Application app;

    Event* event = new KeyEvent(1);
    event->notify();

    return 0;
}