#pragma once

#include "data_frame.h"
#include <string>

namespace pd {
	pd::Data_frame read_csv(std::string path);
}