#include "Integer.h"
#include "Helper.h"

Integer::Integer(int intValue) : _var(intValue)
{
}

int Integer::getVar() const
{
	return this->_var;
}

void Integer::SetVar(int intValue)
{
	this->_var = intValue;
}

std::string Integer::toString() const
{
	return std::to_string(this->_var);
}

bool Integer::isPrintable() const
{
	return true;
}

bool Integer::isInt(std::string& str)
{
	if (str[0] != '-' && !Helper::isDigit(str[0]))
	{
		return false;
	}
	std::string substr = str.substr(1, str.size() - 1);
	for (char& ch : substr)
	{
		if (!Helper::isDigit(ch))
		{
			return false;
		}
	}
	return true;
}