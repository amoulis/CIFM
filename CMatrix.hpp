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
	std::vector< vector<float> > data;
	std::string name;
	
	public:
	
	// Constructors & destructors
	CMatrix(int w, int h);
	CMatrix(int w, int h, vector<vector<float> > tab, std::string newName);
	~CMatrix();
	
	// Setters & Getters
	int getWidth();
	int getHeight();
	float getCoord(int h, int w); // returns value of matrix at coord [h][w]
	void setCoord(int h, int w, float value);
	void setName(std::string newName);
	string getName();
	CMatrix multiplyByMat(CMatrix cm);
	
	// Operations
	bool checkSameSize(CMatrix cm);
	void add(CMatrix cm);
	void addSingElem(float value);
	void multSingElem(float value);
	void multiply(CMatrix cm);
	CMatrix transpose();
	void LUDecomp(CMatrix * L, CMatrix * U);
	float determinant();
	void CholDecomp(CMatrix * L);
	bool isInvertible();
	vector<float> vectByVect(vector<float> s1, vector<float> s2);
	vector<float> matByVect(vector<float> s);
	vector<float> jacobi(vector<float> x0, vector<float> b, int tol);
	float normOfVect(vector<float> v1, vector<float> v2);

	// Print
	void printSize();
	void printMatrix();
	
	// Operators
	CMatrix operator* (const CMatrix & source);
	CMatrix operator* (const float & mult);
	CMatrix operator+ (const CMatrix & source);
	CMatrix operator+ (const float & mult);
	CMatrix operator^ (CMatrix source);
	CMatrix operator- (const CMatrix & source);
	CMatrix operator% (CMatrix source);
};


#endif
