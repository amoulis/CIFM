#include "CStats.hpp"

double CStats::mean(std::vector<double> v)
{
	double s = 0;

	for(int i = 0; i < v.size(); i++)
		s = s + v[i];

	return s / v.size();
}