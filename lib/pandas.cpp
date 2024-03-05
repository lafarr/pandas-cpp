#include "../include/pandas.hpp"
#include "../include/data_frame.hpp"

pd::Data_frame pd::read_csv(std::string path)
{
	return pd::Data_frame{path};
}