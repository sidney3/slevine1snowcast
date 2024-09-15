#pragma once

#include <cstddef>
#include <chrono>

namespace snowcast {

using station_id_t = size_t;
using TimepointT = std::chrono::time_point<std::chrono::system_clock>;
using DurationT = std::chrono::nanoseconds;

} // namespace snowcast