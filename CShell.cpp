#include "CShell.hpp"

using namespace std;

CShell::CShell()
{
	this->data = "default";
	this->nameSession = "defaultName";
	this->lineNumber = 0;
}

CShell::CShell(std::string name, std::string ndata)
{
	this->data = ndata;
	this->nameSession = name;
	this->lineNumber = 0;
}

void CShell::setString(std::string ns)
{
	this->data = ns;
}

std::string CShell::getString()
{
	return this->data;
}

void CShell::DaemonLaunch()
{
	while(this->data!="$exit")
	{
		cout << this->nameSession <<"|" << this->lineNumber++ << ">";
		getline(std::cin,this->data);
		this->data.insert(0, 1,'$'); //signifies ends of array
		cout << analyzeString() << endl;
		this->data.clear();
	}
}

bool CShell::isOperator(char c)
{
	if(c ==  '*' || c == '+' || c ==  '-' || c == '/')
		return true;
	else
		return false;
}

int CShell::getMultDiv(vector<char> op)
{
	for (int i = 0; i < op.size(); i++)
	{
		if(op[i] == '*' || op[i] == '/')
		{
			return i;
		}
	}

	return -1;
}

int CShell::getMinus(vector<char> op)
{
	for (int i = 0; i < op.size(); i++)
	{
		if(op[i] == '-')
		{
			return i;
		}
	}

	return -1;
}

int CShell::getPlus(vector<char> op)
{
	for (int i = 0; i < op.size(); i++)
	{
		if(op[i] == '+')
		{
			return i;
		}
	}

	return -1;
}

double CShell::analyzeString()
{
	double result = 0;
	double temp = 0;
	//double temp2 = 0;
	int power = 0;
	std::vector<double> operands;
	std::vector<char> operators;

	operands.reserve(500);
	operators.reserve(500);

	// Loop in order to stack and differenciate operators from operands
	for (int i = this->data.length()-1 ; i >= 0; i--)
	{
		// find what type of character it is, number or operator
		char c = this->data[i];
		if(isOperator(c) == false)
		{
			temp = temp + atoi(&c) * pow(10, power);
			power++;
		}
		if ( c == '*')
		{
			power = 0;
			operators.push_back('*');
			operands.push_back(temp);
			temp = 0;
		}
		if ( c == '/')
		{
			power = 0;
			operators.push_back('/');
			operands.push_back(temp);
			temp = 0;
		}
		if ( c == '-')
		{
			power = 0;
			operators.push_back('-');
			operands.push_back(temp);
			temp = 0;
		}
		if ( c == '+')
		{
			power = 0;
			operators.push_back('+');
			operands.push_back(temp);
			temp = 0;
		}
		if ( c == '$') // end of array
		{
			operands.push_back(temp);
			power = 0;
			temp = 0;
			break;
		}
	}

	// Loop for computations
	if(operators.size() + 1 == operands.size() )
	{
		for (int i = 0 ; i < operators.size(); i++)
		{
			while(1)
			{
				int k = getMultDiv(operators);
				if(k==-1)
					break;
				else
				{
					if(operators[i] == '*')
					{
						operands[i] = operands[i] * operands[i+1];
						operands.erase(operands.begin()+i+1);
						operators.erase(operators.begin()+i);
					}
					else if (operators[i] == '/')
					{
						operands[i] = operands[i+1] /  operands[i];
						operands.erase(operands.begin()+i+1);
						operators.erase(operators.begin()+i);
					}
				}
			}

			while(1)
			{
				int k = getMinus(operators);
				if(k==-1)
					break;
				else
				{
					if(operators[i] == '-')
					{
						operands[i] = operands[i] - operands[i+1];
						operands.erase(operands.begin()+i+1);
						operators.erase(operators.begin()+i);
					}
				}
			}

			while(1)
			{
				int k = getPlus(operators);
				if(k==-1)
					break;
				else
				{
					if(operators[i] == '+')
					{
						operands[i] = operands[i] + operands[i+1];
						operands.erase(operands.begin()+i+1);
						operators.erase(operators.begin()+i);
					}
				}
			}

		}
		result = operands[0];
		//cout << "power: " << power << "temp: " << temp << "result: " << result << endl;
	}

	return result;
}





