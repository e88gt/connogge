#ifndef UTILS_HPP
#define UTILS_HPP
#endif // UTILS_HPP

#include <cstdint>

#ifndef NS_PER_SEC
#define NS_PER_SEC (1000000000)
#endif // NS_PER_SEC

[[nodiscard]] std::uint64_t systemNanoTime();
