#ifndef PANDAS_H
#define PANDAS_H

#include "data_frame.h"
#include <string>

namespace pd {
	pd::DataFrame ReadCsv(std::string path);
}

#endif