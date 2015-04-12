#ifndef CSTATS_HPP
#define CSTATS_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <algorithm>

class CStats{

public:
	static double mean(std::vector<double> v);
	static double median(std::vector<double> v);
	static double expected(std::vector<double> v, std::vector<double> p);
	static double standardDev(std::vector<double> v);

};
#endif