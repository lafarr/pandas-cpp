#include <iostream>
#include "../include/pandas.hpp"

int main(int argc, char **argv)
{
	auto x = pd::readCsv("/home/james/dev/pandas/test.txt");
	auto row = x[0];
	std::cout << std::get<std::string>(row[0]) << "\n";
	std::cout << std::get<int>(row[1]) << (typeid(decltype(5)) == typeid(std::get<int>(row[1]))) << "\n";
	std::cout << std::get<std::string>(row[2]) << "\n";
    return 0;
}
