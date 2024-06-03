#pragma once
#include <string>


// this is service class with static functions
class Helper
{
public:
	// check if the parameter is valid Integer value
	static bool isInteger(const std::string& s);

	// check if the parameter is valid Boolean value
	static bool isBoolean(const std::string& s);

	// check if the parameter is valid String value
	static bool isString(const std::string& s);

	// check if the parameter is digit
	static bool isDigit(const char c);

	// check if the parameter is lower letter
	static bool isLowerLetter(const char c);	
	
	// check if the parameter is upper letter
	static bool isUpperLetter(const char c);

	// check if the parameter is  letter
	static bool isLetter(const char c);

	// check if the parameter is underscore ('_')
	static bool isUnderscore(const char c);

	// remove whitespace from the begining and the end of the string
	static void trim(std::string &str);

	// remove whitespace from the end of the string
	static void rtrim(std::string &str);  

	// remove whitespace from the beginning of the string
	static void ltrim(std::string &str); 

	// remove leading zeros from the beginning of the string
	static void removeLeadingZeros(std::string &str); 

};
