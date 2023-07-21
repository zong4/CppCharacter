#include "Event.hpp"

std::vector<std::function<void(Event*)>> Event::_callbacks;
