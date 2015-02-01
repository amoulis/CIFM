#ifndef CSHELL_HPP
#define CSHELL_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>

class CShell{

private:
	std::string data;
	std::string nameSession;
	int lineNumber;

public:

	// Constructors
	CShell();
	CShell(std::string name, std::string ndata);

	//Getters and Setters
	void setString(std::string ns);
	std::string getString();

	// Analyze functions
	double analyzeString();
	bool isOperator(char c);

	// Algo functions
	int getMultDiv(std::vector<char> op);

	// Daemon
	void DaemonLaunch();

};

#endif