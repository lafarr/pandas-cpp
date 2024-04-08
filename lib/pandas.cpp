#include "../include/pandas.h"

pd::DataFrame pd::ReadCsv(const std::string &path)
{
    return pd::DataFrame{path};
}