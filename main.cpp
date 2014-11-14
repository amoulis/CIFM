#include <iostream>
#include "CMatrix.hpp"
#include <vector>
#include <string>
#include "analyzeString.hpp"
#include "CShell.hpp"

using namespace std;

int main()
{
	cout << "First line of Compute It For Me" << endl;
	CMatrix a(4, 2);
	vector<vector<float> > v1;
	vector<vector<float> > v2;
	vector<vector<float> > v3;
	
	for (int k = 0; k < 3; k++) 
	{
		vector<float> row; // Create an empty row
		for (int g = 0; g < 2; g++) {
			row.push_back(5); // Add an element (column) to the row
		}
		v3.push_back(row); // Add the row to the main vector
	}
	
	vector<float> row; // Create an empty row
		vector<float> row2; // Create an empty row
	for (int i = 0; i < 2; i++) 
	{
		
		for (int j = 0; j < 2; j++) {
			row.push_back(6); // Add an element (column) to the row
			row2.push_back(5); // Add an element (column) to the row
		}
		v1.push_back(row); // Add the row to the main vector
		v2.push_back(row2); // Add the row to the main vector
	}
	vector<float> row3;
	for (int j = 0; j < 2; j++) {
			row3.push_back(7); // Add an element (column) to the row
		
		}
	std::string nn("coucou");
	CMatrix b(2, 2, v1, nn);
	CMatrix c(2, 2, v2, nn);
	CMatrix d(2, 3, v3, nn);
	
	
	b.printMatrix();
	cout << "------------------------------" << endl;

	CMatrix * la = new CMatrix(2,2);
	
	
	b.setCoord(0,0,2);
	b.setCoord(0,1,6);
	b.setCoord(1,0,6);
	b.setCoord(1,1,20);

	b.printMatrix();
	c.printMatrix();

	b = b-c;
	//b.printMatrix();
	b+8;

	b.printMatrix();

	row3 = b.matByVect(row3);

	b.printMatrix();
	a.~CMatrix();
	
	cout << "Deleted a" << endl;
	
	return 0;
}
