#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <variant>

namespace pd {
	namespace utils {
		std::vector<std::string> split(const std::string str, const char separator);

		bool IsFloat(std::string str);

		bool IsInt(std::string str);

		std::variant<int, std::string, double> ConvertToProperType(std::string str);
	}
}