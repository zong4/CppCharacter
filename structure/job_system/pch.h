#pragma once

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <vector>

#include "Uncopyable.hpp"

using wlock = std::unique_lock<std::shared_mutex>;
using rlock = std::shared_lock<std::shared_mutex>;