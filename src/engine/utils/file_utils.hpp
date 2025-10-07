#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include "types.hpp"

#include <fstream>
#include <sstream>

using InputFileStream = std::ifstream;
using OutputStringStream = std::ostringstream;

namespace File
{
	inline String LoadAsString(const String &path)
	{
		const InputFileStream file{ path, std::ifstream::in | std::ifstream::binary | std::ifstream::ate };

		if (!file)
		{
			throw RuntimeError{ "Failed to load file from (path): '" + path + "'" };
		}

		OutputStringStream buffer{};
		buffer << file.rdbuf();
		return buffer.str();
	}
}

#endif //FILE_UTILS_HPP
