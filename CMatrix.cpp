#include "CMatrix.hpp"

CMatrix::CMatrix(int w, int h)
{
	int i, j;
	
	if(h > 0 && w > 0)
	{
		this->height = h;	
		this->width = w;
	}
	else
	{
			cout << "Error Width or Height not conform" << endl;
			return;
	}
	
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

void CMatrix::multiply(CMatrix cm)
{
		if( this->checkSameSize(cm) == true)
		{
			for(int i = 0; i < this->getHeight(); i++)
				for(int j = 0; j < this->getWidth(); j++)
					this->setCoord(i, j, this->getCoord(i, j) * cm.getCoord(i, j));
		}
		else
			cout << "Matrix dimensions must agree" << endl;
}
CMatrix CMatrix::multiplyByMat(CMatrix cm) // TODO : Implement faster algorithm
{
		float sum = 0;
		CMatrix res(cm.getWidth(), this->getHeight());
		
		if(this->getWidth() == cm.getHeight())
		{
			for(int i = 0; i < res.getWidth(); i++)
			{	
				for(int j = 0; j < res.getHeight(); j++)
				{
					
					for(int k = 0; k < this->getWidth(); k++)
					{	
						res.setCoord(i, j, res.getCoord(i,j) + this->getCoord(i,k) * cm.getCoord(k,j));
					}
					
				}
			}
		return res;
		}
		else
		{
			cout << "Matrix Dimensions must agree" << endl;
			return res;
		}
	
}

void CMatrix::addSingElem(float value)
{
	for(int i = 0; i < this->getHeight(); i++)
		for(int j = 0; j < this->getWidth(); j++)
			this->setCoord(i, j, this->getCoord(i, j) + value);
	
}

void CMatrix::multSingElem(float value)
{
	for(int i = 0; i < this->getHeight(); i++)
		for(int j = 0; j < this->getWidth(); j++)
			this->setCoord(i, j, this->getCoord(i, j) * value);
	
}

CMatrix CMatrix::transpose()
{
		CMatrix cm(this->getHeight(), this->getWidth());
		
		for(int i = 0; i < this->getHeight(); i++)
			for(int j = 0; j < this->getWidth(); j++)
				cm.setCoord(j,i, this->getCoord(i, j));
		
		return cm;
}


void CMatrix::LUDecomp(CMatrix * L, CMatrix * U)
{
	if(this->getHeight() != this->getWidth())
	{
		cout << "LU Decomposition is for square matrix only" <<endl;
		return;
	}
	else
	{
		const int n = this->getHeight();

		for(int k = 0; k < n; k++)
		{
			L->setCoord(k,k, 1);
			for(int i = k+1; i < n; i++)
			{
				L->setCoord(i, k, this->getCoord(i, k)/this->getCoord(k,k));
				for(int j = k+1; j < n; j++)
				{
					this->setCoord(i, j, this->getCoord(i, j) - L->getCoord(i, k)*this->getCoord(k, j));
				} 
			}
			for(int j=k; j<n; j++)
				U->setCoord(k, j, this->getCoord(k, j));
		}
	}
}

CMatrix CMatrix::operator+ (const CMatrix & source)
{
	this->add(source);
	return *this;
}

CMatrix CMatrix::operator* (const CMatrix & source)
{
	return multiplyByMat(source);
}

float CMatrix::determinant()
{
	if(this->getHeight() != this->getWidth())
	{
		cout << "This method is for square matrix only" <<endl;
		return -1;
	}
	else
	{
		int n = this->getHeight();
		CMatrix * L = new CMatrix(n,n);
		CMatrix * U = new CMatrix(n,n);

		this->LUDecomp(L, U);

		float detu = 1, detl = 1;

		for(int i = 0; i <n; i++)
		{
			detl = detu*L->getCoord(i,i);
			detu = detu*U->getCoord(i,i);
		}
		
		return detl*detu;
	}

}