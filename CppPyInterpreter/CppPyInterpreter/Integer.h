#pragma once
#include "Type.h"

class Integer : public Type
{
public:
	Integer(int intValue);

	int getVar() const;
	void SetVar(int intValue);

	virtual std::string toString() const override;
	virtual bool isPrintable() const override;

	static bool isInt(std::string& str);
	

private:
	int _var;
};