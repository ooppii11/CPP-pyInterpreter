#include "Type.h"
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Itamar.H-L"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	while (input_string != "quit()")
	{
		try
		{
			// parsing command
			Type* var = Parser::parseString(input_string);
			if (var->isPrintable())
			{
				std::cout << var->toString() << std::endl;
			}
			if (var->getIsTemp())
			{
				delete var;
			}
		}
		catch (InterpreterException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}
	
	return 0;
}
