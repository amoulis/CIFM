#include "CShell.hpp"


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