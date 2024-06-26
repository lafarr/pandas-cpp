#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

#include "../include/dataFrame.h"
#include "../util/utils.hpp"

pd::DataFrame::DataFrame(const std::string &path)
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
        m_cols = pd::utils::split(line, ',');
        for (std::string &col: m_cols) {
            m_matrix[col] = std::vector<std::string>{};
        }
    }

    // read data
    while (std::getline(file_reader, line)) {
        std::vector<std::string> tokens = pd::utils::split(line, ',');
        for (int i = 0; i < tokens.size(); ++i) {
            m_matrix.at(m_cols[i]).push_back(tokens[i]);
        }
    }
}

std::vector<std::variant<int, std::string, double>> pd::DataFrame::GetColumnByName(const std::string &columnName)
{
    std::vector<std::variant<int, std::string, double>> vec{};
    try {
        std::transform(m_matrix.at(columnName).begin(), m_matrix.at(columnName).end(), std::back_inserter(vec),
                       pd::utils::ConvertToProperType);
    }
    catch (std::out_of_range &ex) {
        throw std::out_of_range("Column " + columnName + std::string(" does not exist in the DataFrame instance"));
    }
    return vec;
}

std::vector<std::variant<int, std::string, double>> pd::DataFrame::GetColumnByIndex(std::size_t index)
{
    std::vector<std::variant<int, std::string, double>> vec{};
    std::vector<std::string> col;
    try {
        col = m_matrix.at(m_cols[index]);
    }
    catch (std::out_of_range &ex) {
        throw ex;
    }
    std::transform(col.begin(), col.end(), std::back_inserter(vec), pd::utils::ConvertToProperType);
    return vec;
}

std::vector<std::variant<int, std::string, double>> pd::DataFrame::GetRow(std::size_t index)
{
    std::vector<std::variant<int, std::string, double>> vec{};
    for (std::string &col_name: m_cols) {
        vec.emplace_back(m_matrix.at(col_name)[index]);
    }
    for (auto & it : vec) {
        it = pd::utils::ConvertToProperType(std::get<std::string>(it));
    }
    return vec;
}

std::vector<std::variant<int, std::string, double>> pd::DataFrame::operator[](std::size_t index)
{
    return pd::DataFrame::GetRow(index);
}