#ifndef PANDAS_H
#define PANDAS_H

#include "dataFrame.h"
#include <string>

namespace pd {
	pd::DataFrame ReadCsv(std::string path);
}

#endif