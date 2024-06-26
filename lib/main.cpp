#include <iostream>
#include "../include/pandas.h"

int main(int argc, char **argv)
{
    auto x = pd::ReadCsv("/home/james/dev/pandas-cpp/test.txt");
    auto row = x[0];
    std::cout << std::get<std::string>(row[0]) << "\n";
    if (typeid(decltype(5)) == typeid(std::get<int>(row[1]))) {
        std::cout << std::get<int>(row[1]) << '\n';
    }
    std::cout << std::get<std::string>(row[2]) << "\n";
    return 0;
}
