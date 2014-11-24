#ifndef CSHELL_HPP
#define CSHELL_HPP

#include <string>

class CShell{

private:
	std::string data;
	std::string nameSession;
	int lineNumber;

public:
	CShell();
	CShell(std::string name, std::string ndata);

};

#endif