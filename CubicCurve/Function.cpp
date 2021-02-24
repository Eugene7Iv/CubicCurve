#include "Function.h"
#include <limits>

std::pair<double, double> Function::domain() const
{
	double min = std::numeric_limits<double>::lowest();
	double max = std::numeric_limits<double>::max();
	return std::pair<double, double>{min, max};
}
