#ifndef CSHELL_HPP
#define CSHELL_HPP

#include <string>
#include <cstring>
#include <iostream>

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


	// Daemon
	void DaemonLaunch();

};

#endif