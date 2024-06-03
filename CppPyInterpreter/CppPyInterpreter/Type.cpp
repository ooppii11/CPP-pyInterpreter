#include "Type.h"

Type::Type() : _isTemp(false)
{
}

Type::Type(bool isTemp) : _isTemp(isTemp)
{
}

bool Type::getIsTemp() const
{
    return this->_isTemp;
}

void Type::setIsTemp(const bool& isTemp)
{
    this->_isTemp = isTemp;
}