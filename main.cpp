#include <iostream>
#include "CMatrix.hpp"
#include <vector>
#include <string>

using namespace std;

int main()
{
	cout << "First line of Compute It For Me" << endl;
	CMatrix a(4, 2);
	vector<vector<float> > v1;
	vector<vector<float> > v2;
	
	for (int i = 0; i < 2; i++) 
	{
		vector<float> row; // Create an empty row
		vector<float> row2; // Create an empty row
		for (int j = 0; j < 2; j++) {
			row.push_back(6); // Add an element (column) to the row
			row2.push_back(5); // Add an element (column) to the row
		}
		v1.push_back(row); // Add the row to the main vector
		v2.push_back(row2); // Add the row to the main vector
	}
	
	std::string nn("coucou");
	CMatrix b(2, 2, v1, nn);
	CMatrix c(2, 2, v2, nn);
	
	
	
	a.printSize();
	cout << a.getCoord(1, 1) << endl;
	a.printMatrix();
	
	b.printMatrix();
	b.add(c);
	
	b.printMatrix();
	
	b.addSingElem(2);
	
	b.printMatrix();
	
	a.~CMatrix();
	
	cout << "Deleted a" << endl;
	
	return 0;
}

