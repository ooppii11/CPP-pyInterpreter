#include "Boolean.h"

Boolean::Boolean(bool boolValue) : _var(boolValue)
{
}

bool Boolean::getVar() const
{
    return this->_var;
}

void Boolean::SetVar(bool boolValue)
{
	this->_var = boolValue;
}

std::string Boolean::toString() const
{
	if (this->_var)
	{
		return "True";
	}
    return "False";
}

bool Boolean::isPrintable() const
{
    return true;
}


bool Boolean::toBool(std::string& str)
{
	if (str == "True")
	{
		return true;
	}
	else
	{
		return false;
	}
}
