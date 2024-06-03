#pragma once
#include "InterpreterException.h"
#include "Type.h"
#include "Helper.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>


class Parser
{
public:
	static Type* parseString(std::string str);
	static Type* getType(std::string& str);

private:
	static bool isLegalVarName(std::string name);
	static bool makeAssignment(std::string str);
	static Type* getVariableValue(std::string varName);

	static std::unordered_map<std::string, Type*> _variables;
};
