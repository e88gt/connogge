#ifndef TIME_HPP
#define TIME_HPP
#include <chrono>

namespace Time
{
	inline constexpr int NS_PER_SEC = 1000000000;

	inline unsigned long long Nano()
	{
		return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	}
}

#endif //TIME_HPP
