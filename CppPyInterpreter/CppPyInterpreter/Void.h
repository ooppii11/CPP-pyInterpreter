#pragma once
#include "Type.h"

class Void : public Type
{
public:
	virtual std::string toString() const override;
	virtual bool isPrintable() const override;
};