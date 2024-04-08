#pragma once

#include <string>
#include <vector>
#include <variant>
#include <cstddef>
#include <unordered_map>

namespace pd
{
	class DataFrame
	{
	public:
		DataFrame(std::string path);

		std::vector<std::variant<int, std::string, double>> GetColumnByName(std::string columnName);

		std::vector<std::variant<int, std::string, double>> GetColumnByIndex(std::size_t index);

		std::vector<std::variant<int, std::string, double>> GetRow(std::size_t index);

		std::vector<std::variant<int, std::string, double>> operator[](std::size_t index);

	private:
		std::unordered_map<std::string, std::vector<std::string>> m_matrix;
		std::vector<std::string> m_cols;
	};
}