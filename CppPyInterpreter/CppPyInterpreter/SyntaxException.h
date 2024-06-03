#pragma once
#include "InterpreterException.h"
class SyntaxException : public InterpreterException
{
public:
	virtual const char* what() const;

};