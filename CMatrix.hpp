#ifndef CMATRIX_HPP
#define CMATRIX_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class CMatrix {

	private:

	int width ; // Number of columns
	int height; // Number of lines
	std::vector< vector<double> > data;
	std::string name;

	public:

	// Constructors & destructors
	CMatrix(int w, int h);
	CMatrix(int w, int h, vector<vector<double> > tab, std::string newName);
	~CMatrix();

	// Setters & Getters
	int getWidth();
	int getHeight();
	double getCoord(int h, int w); // returns value of matrix at coord [h][w]
	void setCoord(int h, int w, double value);
	void setName(std::string newName);
	string getName();
	CMatrix multiplyByMat(CMatrix cm);

	// Operations
	bool checkSameSize(CMatrix cm);
	void add(CMatrix cm);
	void addSingElem(double value);
	void multSingElem(double value);
	void multiply(CMatrix cm);
	CMatrix transpose();
	void LUDecomp(CMatrix * L, CMatrix * U);
	double determinant();
	void CholDecomp(CMatrix * L);
	bool isInvertible();
	vector<double> vectByVect(vector<double> s1, vector<double> s2);
	vector<double> matByVect(vector<double> s);
	vector<double> jacobi(vector<double> x0, vector<double> b, int tol);
	double normOfVect(vector<double> v1, vector<double> v2);

	// Print
	void printSize();
	void printMatrix();

	// Operators
	CMatrix operator* (const CMatrix & source);
	CMatrix operator* (const double & mult);
	CMatrix operator+ (const CMatrix & source);
	CMatrix operator+ (const double & mult);
	CMatrix operator^ (CMatrix source);
	CMatrix operator- (const CMatrix & source);
	CMatrix operator% (CMatrix source);
};


#endif
