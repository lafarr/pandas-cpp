#ifndef PANDAS_H
#define PANDAS_H

#include "dataFrame.h"
#include <string>

namespace pd {
    pd::DataFrame ReadCsv(const std::string &path);
}

#endif