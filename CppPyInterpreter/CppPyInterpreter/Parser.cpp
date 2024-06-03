#include "Parser.h"
#include <iostream>
#include <algorithm>
#include "IndentationException.h"
#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "SyntaxException.h"
#include "Void.h"
#include "NameErrorException.h"


bool invalidStartwith(std::string str, std::string invalidChars);
std::vector<std::string> split(std::string str, char splitChar);
std::unordered_map<std::string, Type*> Parser::_variables;

Type* Parser::parseString(std::string str)
{
	Helper::rtrim(str);
	if (invalidStartwith(str, " \t"))
	{
		throw IndentationException();
	}
	Type* temp = Parser::getType(str);
	if (temp == nullptr)
	{
		if (makeAssignment(str))
		{
			temp = new Void();
			temp->setIsTemp(true);
		}
		else
		{
			if (!Parser::isLegalVarName(str))
			{
				throw SyntaxException();
			}
			temp = Parser::getVariableValue(str);
			if (temp == nullptr)
			{
				throw NameErrorException(str);
			}
		}
	}
	else
	{
		temp->setIsTemp(true);
	}
	return temp;
}

Type* Parser::getType(std::string& str)
{
	Helper::trim(str);
	if (Helper::isBoolean(str))
	{
		return new Boolean(Boolean::toBool(str));
	}
	else if (Integer::isInt(str))
	{
		return new Integer(std::atoi(str.c_str()));
	}
	else if (Helper::isString(str))
	{
		return new String(str);
	}
	return nullptr;
}


bool Parser::isLegalVarName(std::string name)
{
	if (!(Helper::isLetter(name[0]) || Helper::isUnderscore(name[0])))
	{
		return false;
	}
	std::string substr = name.substr(1, name.size() - 1);
	for (char& ch : substr)
	{
		if (!(Helper::isLetter(ch) || Helper::isUnderscore(ch) || Helper::isDigit(ch)))
		{
			return false;
		}
	}
	return true;
}

bool Parser::makeAssignment(std::string str)
{
	std::string substr = str.substr(1, str.size() - 2);
	std::vector<std::string> commandVector = split(str, '=');
	
	if (str[0] == '=' || str[str.size() - 1] == '=')
	{
		return false;
	}
	else if (std::count(substr.begin(), substr.end(), '=') != 1)
	{
		return false;
	}
	else if (!Parser::isLegalVarName(commandVector[0]))
	{
		throw SyntaxException();
	}
	Type* val = Parser::getType(commandVector[1]);
	if (val == nullptr && !Parser::isLegalVarName(commandVector[1]))
	{
		throw SyntaxException();
	}
	else if (val == nullptr)
	{
		std::string tempVal = getVariableValue(commandVector[1])->toString();
		val = Parser::getType(tempVal);
		if (val == nullptr)
		{
			throw NameErrorException(commandVector[1]);
		}
	}
	

	
	Parser::_variables[commandVector[0]] = val;
	return true;
}


Type* Parser::getVariableValue(std::string varName)
{
	auto varValue = Parser::_variables.find(varName);
	if (varValue == Parser::_variables.end())
	{
		return nullptr;
	}
	return varValue->second;
}

std::vector<std::string> split(std::string str, char splitChar)
{
	std::vector<std::string> splited;
	std::string temp = "";
	for (char& ch : str)
	{
		if (ch != splitChar && ch != ' ' && ch != '\t')
		{
			temp += ch;
		}
		else
		{
			if (temp != "")
			{
				splited.push_back(temp);
				temp = "";
			}
		}
	}
	if (temp != "")
	{
		splited.push_back(temp);
		temp = "";
	}
	return splited;
}


bool invalidStartwith(std::string str, std::string invalidChars)
{
	for (char& ch : invalidChars)
	{
		if (str[0] == ch)
		{
			return true;
		}
	}
	return false;
}


