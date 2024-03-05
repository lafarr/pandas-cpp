#pragma once

#include <string>
#include <vector>
#include <variant>
#include <cstddef>
#include <unordered_map>

namespace pd {
	class Data_frame {
	public:
		Data_frame(std::string path);

		std::vector<std::variant<int, std::string, double>> get_column_by_name(std::string columnName);

		std::vector<std::variant<int, std::string, double>> get_column_by_index(std::size_t index);

		std::vector<std::variant<int, std::string, double>> get_row(std::size_t index);

		std::vector<std::variant<int, std::string, double>> operator[](std::size_t index);

	private:
		std::unordered_map<std::string, std::vector<std::string>> m_matrix;
		std::vector<std::string> m_cols;
	};
}