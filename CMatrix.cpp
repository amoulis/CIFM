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

void CMatrix::CholDecomp(CMatrix * L)
{
	if(this->getHeight() != this->getWidth())
	{
		cout << "Cholesky Decomposition is for square matrix only" <<endl;
		return;
	}
	else
	{
		const int n = this->getHeight();

		double S;
		int i, j, k;
		for(j=0; j< n;j++)
		{
			S = 0;

			for(k=0; k<j; k++)
				S+=L->getCoord(j,k)*L->getCoord(j, k);

			L->setCoord(j,j,sqrt(this->getCoord(j,j)-S));

			for(i=j; i<n; i++)
			{
				S = 0;
				for(k=0; k<j; k++)
					S+=L->getCoord(i,k)*L->getCoord(j,k);
				L->setCoord(i,j,(this->getCoord(i,j)-S)/L->getCoord(j,j));
			}
		}
	}
	*L = L->transpose();
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

bool CMatrix::isInvertible()
{
	if(this->determinant() != 0)
		return true;
	else
		return false;
}

vector<float> CMatrix::vectByVect(vector<float> s1, vector<float> s2)
{

	vector<float> res = s1;

	if(s1.size() != s2.size())
	{
		cout << "Error vector dimensions must agree" << endl;
		return s1;
	}
	else
	{
		for(int i= 0; i < s1.size(); i++)
			res[i] = s1[i] * s2[i];

	}

	return res;
}

vector<float> CMatrix::matByVect(vector<float> s)
{
	int n = s.size();
	int r;
	vector<float> res = s;

	if(s.size() != this->getHeight() && s.size() != this->getWidth())
	{
		cout << "At least one dimension must agree matrix x vector" << endl;
		return s;
	}
	else
	{
		if(n == this->getWidth())
			r = this->getWidth();
		if(n == this->getHeight())
			r = this->getHeight();

		for(int j = 0; j < n; j++)
		{
			res[j] = 0;
			for(int i = 0; i < r; i++)
			{
				res[j] += this->getCoord(i,j)*s[i];
			}
		}
	}

	return res;
}
vector<float> CMatrix::jacobi(vector<float> x0, vector<float> b, int tol)
{

	vector<float> x;
	vector< vector<float> > res;

	while((normOfVect(x, x0) < tol))
	{
		for(int i = 0; i < this->getWidth(); i++)
		{
			float sum = 0;
			for(int j = 0; j < this->getHeight(); j++)
			{
				sum += (-1 * this->getCoord(i,j) * x0[j] +b[i]);
			}

			x[i] = 1/this->getCoord(i,i);
		}
		x0 = x;
		res.push_back(x);
	}
	return x;
}

float CMatrix::normOfVect(vector<float> v1, vector<float> v2)
{

	int i;

	if(v1.size()!=v2.size())
	{
		cout << "Error vector must have same size" << endl;
		return -1;
	}
	else
	{
		float sum = 0;
		for(i = 0; i < v2.size(); i++)
		{
			v1[i] = v1[i] - v2[i];
			sum += v1[i] * v1[i];
		}

		return sqrt(sum);
	}

}

/* OPERATORS */

CMatrix CMatrix::operator+ (const CMatrix & source)
{
	this->add(source);
	return *this;
}

CMatrix CMatrix::operator* (const CMatrix & source)
{
	return multiplyByMat(source);
}
CMatrix CMatrix::operator^ (CMatrix source)
{
	source = source.transpose();
}

CMatrix CMatrix::operator* (const float & mult)
{
	this->multSingElem(mult);
	return *this;
}

CMatrix CMatrix::operator+ (const float & mult)
{
	this->addSingElem(mult);
	return *this;
}

CMatrix CMatrix::operator- (const CMatrix & source)
{
	CMatrix temp(this->getWidth(), this->getHeight());
	temp = source;
	temp = temp*(-1);

	this->add(temp);

	return *this;
}
CMatrix CMatrix::operator% (CMatrix source)
{
	CMatrix nm = source;

	if(this->getWidth() != source.getWidth() || this->getHeight() != source.getHeight())
	{
		cout << "error, matrix dimension must agree" << endl;
		return *this;
	}

	for(int i = 0; i < this->getWidth(); i++)
		for(int j = 0; j < this->getHeight(); j++)
			nm.setCoord(i, j, source.getCoord(i,j)*this->getCoord(i, j));


	return nm;
}