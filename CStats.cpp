#include "CStats.hpp"
#include "CMatrix.hpp"

double CStats::mean(std::vector<double> v)
{
	double s = 0;

	for(int i = 0; i < v.size(); i++)
		s = s + v[i];

	return s / v.size();
}

double CStats::median(std::vector<double> v)
{
	double m;
	std::sort(v.begin(), v.end());

	if(v.size()%2 == 0)
		m = (v[v.size()/2] + v[(v.size()/2)+1]) / 2;
	else
		m = v[(v.size()/2)];

	return m;
}

double CStats::expected(std::vector<double> v, std::vector<double> p)
{
	std::vector<double> r = CMatrix::vectByVect(v, p);
	double expect = 0;
	for(int i = 0; i < r.size(); i++)
		expect = expect + r[i];

	return expect;
}