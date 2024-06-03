#include "String.h"

String::String(std::string stringValue) : _var(stringValue)
{
}

std::string String::getVar() const
{
	return this->_var;
}

void String::SetVar(std::string stringValue)
{
	this->_var = stringValue;
}

std::string String::toString() const
{
	return this->_var;
}

bool String::isPrintable() const
{
	return true;
}
