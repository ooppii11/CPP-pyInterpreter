#pragma once
#include <string>
#include "InterpreterException.h"

class NameErrorException : public InterpreterException
{
public:
	NameErrorException(char* name);
	NameErrorException(const char* name);
	NameErrorException(std::string& name);

	~NameErrorException();


	virtual const char* what() const;


private:
	char* _error;
};