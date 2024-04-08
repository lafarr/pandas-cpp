#include <variant>
#include <string>
#include <stdexcept>
#include "utils.hpp"

std::vector<std::string> pd::utils::split(const std::string &str, const char separator)
{
	// Find the first appearance of separator in str, and if it isn't present,
	// return str
	std::vector<std::string> tokens{};
	std::size_t indexOfSeparator = str.find(separator);
	if (indexOfSeparator == std::string::npos) {
		return std::vector{str};
	}

	// Keep finding the next index of separator, and then add a substring of
	// the last found position of [separator + 1, next separator position)
	std::size_t currentIndex = 0;
	while (indexOfSeparator != std::string::npos) {
		tokens.push_back(str.substr(currentIndex, indexOfSeparator - currentIndex));
        currentIndex = indexOfSeparator + 1;
        indexOfSeparator = str.find(separator, currentIndex);
		// To get the last token
		if (indexOfSeparator == std::string::npos && ((indexOfSeparator + 1) < str.size())) {
			tokens.push_back(str.substr(currentIndex, str.size()));
		}
	}
	return tokens;
}

bool pd::utils::IsInt(const std::string &str)
{
	try {
		return std::to_string(std::stoi(str)) == str;
	} catch (std::invalid_argument& ex) {
		return false;
	}
}

bool pd::utils::IsFloat(const std::string &str)
{
	try {
		return std::to_string(std::stof(str)) == str;
	} catch (std::invalid_argument& ex) {
		return false;
	}
}

std::variant<int, std::string, double> pd::utils::ConvertToProperType(std::string str)
{
	if (pd::utils::IsInt(str)) {
		return std::stoi(str);
	}
	else if (pd::utils::IsFloat(str)) {
		return std::stof(str);
	}
	return str;
}