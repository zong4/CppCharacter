#pragma once

#include <deque>
#include <mutex>
#include <shared_mutex>

using wlock = std::unique_lock<std::shared_mutex>;
using rlock = std::shared_lock<std::shared_mutex>;