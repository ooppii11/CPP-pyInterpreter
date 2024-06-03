#include "Helper.h"


bool Helper::isInteger(const std::string& s)
{
	int start = (s[0] == '-') ? 1 : 0;
	for (int i = start; i < s.size(); i++)
	{
		if (!isDigit(s[i]))
		{
			return false;
		}
	}

	return true;
}

bool Helper::isBoolean(const std::string& s)
{
	return (s == "True" || s == "False");
}


bool Helper::isString(const std::string& s)
{
	size_t end = s.size() - 1;

	if (s[0] == '\"' && end == s.find('\"', 1))
	{
		return true;
	}
	if (s[0] == '\'' && end == s.find('\'', 1))
	{
		return true;
	}

	return false;

}

bool Helper::isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}

void Helper::trim(std::string &str)
{
	rtrim(str);
	ltrim(str);

}

void Helper::rtrim(std::string &str)
{
	size_t endpos = str.find_last_not_of(" \t");
	if (std::string::npos != endpos)
	{
		str = str.substr(0, endpos + 1);
	}
}

void Helper::ltrim(std::string &str)
{
	size_t startpos = str.find_first_not_of(" \t");
	if (std::string::npos != startpos)
	{
		str = str.substr(startpos);
	}
}

void Helper::removeLeadingZeros(std::string &str)
{
	size_t startpos = str.find_first_not_of("0");
	if (std::string::npos != startpos)
	{
		str = str.substr(startpos);
	}
}




bool Helper::isLowerLetter(const char c)
{
	return (c >= 'a' && c <= 'z');
}

bool Helper::isUpperLetter(const char c)
{
	return (c >= 'A' && c <= 'Z');
}

bool Helper::isLetter(const char c)
{
	return (isLowerLetter(c) || isUpperLetter(c));
}

bool Helper::isUnderscore(const char c)
{
	return ('_' == c);
}

