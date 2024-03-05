#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <variant>

namespace pd {
	namespace utils {
		std::vector<std::string> split(const std::string str, const char separator);

		bool is_float(std::string str);

		bool is_int(std::string str);

		std::variant<int, std::string, double> convert_to_proper_type(std::string str);
	}
}