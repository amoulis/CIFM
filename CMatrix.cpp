#include "CMatrix.hpp"

CMatrix::CMatrix(int w, int h)
{
	int i, j;
	
	this->height = h;
	this->width = w;
	
	this->name = string();
	
	for (i = 0; i < height; i++) 
	{
		vector<float> row; // Create an empty row
		for (j = 0; j < width; j++) {
			row.push_back(0.0); // Add an element (column) to the row
		}
		this->data.push_back(row); // Add the row to the main vector
	}
	
}

CMatrix::CMatrix(int w, int h, vector<vector<float> > tab, std::string newName)
{
	int i, j;
	
	this->height = h;
	this->width = w;
	
	this->name = string(newName);
	
	for (i = 0; i < height; i++) 
	{
		vector<float> row; // Create an empty row
		for (j = 0; j < width; j++) {
			row.push_back(tab[i][j]); // Add an element (column) to the row
		}
		this->data.push_back(row); // Add the row to the main vector
	}
	
}

void CMatrix::setCoord(int h, int w, float value)
{
	if( h < this->getHeight() && h >= 0)
		if( w < this->getWidth() && w >= 0)
				this->data[h][w] = value;
}

CMatrix::~CMatrix()
{
		// free vector memory
		vector<vector<float> >().swap(this->data);
}

int CMatrix::getWidth()
{
	return this->width;	
}
int CMatrix::getHeight()
{
		return this->height;
}

float CMatrix::getCoord(int h, int w)
{
	if( h < this->getHeight() && h >= 0)
		if( w < this->getWidth() && w >= 0)
			return this->data[h][w];
}

void CMatrix::printMatrix()
{
	int i, j;
	
	if(this->name.empty() == true)
		cout << " Matrix :" << endl;
	else
		cout << this->name << endl;
	cout << "[" << endl;
	
	for(i = 0; i < this->getHeight(); i++)
	{
		for(j = 0; j < this->getWidth(); j++)
		{
				cout << this->getCoord(i, j);
				cout << ";";
		}
		cout << " " << endl;
	}
	
	cout << "]" << endl;
}

void CMatrix::printSize()
{
	cout << this->getWidth() << endl;
	cout << this->getHeight() << endl;
}

void CMatrix::setName(string newName)
{
		this->name = newName;
}

string CMatrix::getName()
{
	return this->name;
}

bool CMatrix::checkSameSize(CMatrix cm)
{
		if(this->width == cm.getWidth() && this->height == cm.getHeight())
			return true;
		else
			return false;
}

void CMatrix::add(CMatrix cm)
{
		if( this->checkSameSize(cm) == true)
		{
			for(int i = 0; i < this->getHeight(); i++)
				for(int j = 0; j < this->getWidth(); j++)
					this->setCoord(i, j, this->getCoord(i, j) + cm.getCoord(i, j));
		}
		else
			cout << "Matrix dimensions must agree" << endl;
}
void CMatrix::addSingElem(float value)
{
	for(int i = 0; i < this->getHeight(); i++)
		for(int j = 0; j < this->getWidth(); j++)
			this->setCoord(i, j, this->getCoord(i, j) + value);
	
}
