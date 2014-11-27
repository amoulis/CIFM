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
	while(this->data!="exit")
	{
		cout << this->nameSession <<"|" << this->lineNumber++ << " >";
		getline(std::cin,data);
		// call analyze
	}
}