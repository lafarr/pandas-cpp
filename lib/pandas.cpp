#include "../include/pandas.h"
#include "../include/data_frame.h"

pd::DataFrame pd::ReadCsv(std::string path)
{
	return pd::DataFrame{path};
}