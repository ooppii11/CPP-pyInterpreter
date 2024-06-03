#pragma once
#include "Type.h"

class Sequence : public Type
{
public:
	virtual std::string toString() const = 0;
	virtual bool isPrintable() const = 0;
};