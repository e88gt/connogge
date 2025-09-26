#include "Time.hpp"

#include <cstdint>
#include <chrono>

std::uint64_t systemNanoTime()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()
		).count();
}
