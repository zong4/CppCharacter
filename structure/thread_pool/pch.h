#pragma once

#include <mutex>
#include <queue>
#include <shared_mutex>

using wlock = std::unique_lock<std::shared_mutex>;
using rlock = std::shared_lock<std::shared_mutex>;