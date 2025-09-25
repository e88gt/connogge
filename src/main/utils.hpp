#ifndef _UTILS_HPP
#define _UTILS_HPP

#include <iostream>

#ifndef ERROR
#define ERROR(msg) \
{ \
	std::cerr << msg << "\n"; \
	std::exit(EXIT_FAILURE); \
}
#endif // ERROR

#endif // _UTILS_HPP
