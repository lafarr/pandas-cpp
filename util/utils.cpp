#include <variant>
#include <string>
#include <stdexcept>
#include "utils.hpp"

std::vector<std::string> pd::utils::split(const std::string str, const char separator)
{
	// Find the first appearance of separator in str, and if it isn't present,
	// return str
	std::vector<std::string> tokens{};
	std::string str_copy = str;
	int index_of_sep = str_copy.find(separator);
	if (index_of_sep == std::string::npos) {
		return std::vector{str};
	}

	// Keep finding the next index of separator, and then add a substring of
	// the last found position of [separator + 1, next separator position)
	int curr_index = 0;
	while (index_of_sep != std::string::npos) {
		tokens.push_back(str.substr(curr_index, index_of_sep - curr_index));
		curr_index = index_of_sep + 1;
		str_copy = str.substr(curr_index);
		index_of_sep = str.find(separator, curr_index);
		// To get the last token
		if (index_of_sep == std::string::npos && ((index_of_sep + 1) < str.size())) {
			tokens.push_back(str.substr(curr_index, str.size()));
		}
	}
	return tokens;
}

bool pd::utils::is_int(std::string str)
{
	try {
		return std::to_string(std::stoi(str)) == str;
	} catch (std::invalid_argument& ex) {
		return false;
	}
}

bool pd::utils::is_float(std::string str)
{
	try {
		return std::to_string(std::stof(str)) == str;
	} catch (std::invalid_argument& ex) {
		return false;
	}
}

std::variant<int, std::string, double> pd::utils::convert_to_proper_type(std::string str)
{
	if (pd::utils::is_int(str)) {
		return std::stoi(str);
	}
	else if (pd::utils::is_float(str)) {
		return std::stof(str);
	}
	return str;
}