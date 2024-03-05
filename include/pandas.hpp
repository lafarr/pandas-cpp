#pragma once

#include "data_frame.hpp"
#include <string>

namespace pd {
	pd::Data_frame read_csv(std::string path);
}