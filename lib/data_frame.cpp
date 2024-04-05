#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

#include "../include/data_frame.h"
#include "../util/utils.hpp"

pd::Data_frame::Data_frame(const std::string path)
{
	// open file
	std::ifstream file_reader;
	try {
		file_reader.open(path);
	}
	catch (const std::exception &ex) {
		std::cerr << "Could not open the given file" << "\n";
		std::cerr << ex.what() << "\n";
		throw ex;
	}

	// read column names
	std::string line;
	if (std::getline(file_reader, line)) {
		cols_ = pd::utils::split(line, ',');
		for (std::string &col: cols_) {
			matrix_[col] = std::vector<std::string>{};
		}
	}

	// read data
	while (std::getline(file_reader, line)) {
		std::vector<std::string> tokens = pd::utils::split(line, ',');
		for (int i = 0; i < tokens.size(); ++i) {
			matrix_.at(cols_[i]).push_back(tokens[i]);
		}
	}
}

std::vector<std::variant<int, std::string, double>> pd::Data_frame::get_column_by_name(std::string columnName)
{
	std::vector<std::variant<int, std::string, double>> vec{};
	try {
		std::transform(matrix_.at(columnName).begin(), matrix_.at(columnName).end(), std::back_inserter(vec),
					   pd::utils::convert_to_proper_type);
	}
	catch (std::out_of_range &ex) {
		throw std::out_of_range("Column " + columnName + std::string(" does not exist in the data_frame instance"));
	}
	return vec;
}

std::vector<std::variant<int, std::string, double>> pd::Data_frame::get_column_by_index(std::size_t index)
{
	std::vector<std::variant<int, std::string, double>> vec{};
	std::vector<std::string> col;
	try {
		col = matrix_.at(cols_[index]);
	}
	catch (std::out_of_range &ex) {
		throw ex;
	}
	std::transform(col.begin(), col.end(), std::back_inserter(vec), pd::utils::convert_to_proper_type);
	return vec;
}

std::vector<std::variant<int, std::string, double>> pd::Data_frame::get_row(std::size_t index)
{
	std::vector<std::variant<int, std::string, double>> vec{};
	for (std::string &col_name: cols_) {
		vec.push_back(matrix_.at(col_name)[index]);
	}
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		*it = pd::utils::convert_to_proper_type(std::get<std::string>(*it));
	}
	return vec;
}

std::vector<std::variant<int, std::string, double>> pd::Data_frame::operator[](std::size_t index)
{
	return pd::Data_frame::get_row(index);
}