#include <iostream>
#include "CMatrix.hpp"
#include <vector>
#include <string>
#include "CStats.hpp"

using namespace std;

int main(void)
{

	std::vector<double> v;
	v.push_back(4);
	v.push_back(6);
	cout << CStats::mean(v) << endl;
	return 0;
}
