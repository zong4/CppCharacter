#pragma once

#include <mutex>
#include <shared_mutex>
#include <vector>

using wlock = std::unique_lock<std::shared_mutex>;
using rlock = std::shared_lock<std::shared_mutex>;