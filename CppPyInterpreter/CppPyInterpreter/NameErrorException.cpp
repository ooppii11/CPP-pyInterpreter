#include "NameErrorException.h"
NameErrorException::NameErrorException(char* name)
{
    std::string fullError = "“NameError : name ‘" + std::string(name) + "’ is not defined” : ";
    this->_error = new char[fullError.size() + 1];
    strcpy(this->_error, fullError.c_str());
    this->_error[fullError.size()] = 0;
}

NameErrorException::NameErrorException(std::string& name)
{
    std::string fullError = "\"NameError : name \'" + name + "\' is not defined\"";
    this->_error = new char[fullError.size() + 1];
    strcpy(this->_error, fullError.c_str());
    this->_error[fullError.size()] = 0;
}

NameErrorException::~NameErrorException()
{
    delete[] this->_error;
}

const char* NameErrorException::what() const
{
    return this->_error;
}
