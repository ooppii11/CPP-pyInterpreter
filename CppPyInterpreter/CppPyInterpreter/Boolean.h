#pragma once
#include "Type.h"

class Boolean : public Type
{
public:
	Boolean(bool boolValue);

	bool getVar() const;
	void SetVar(bool boolValue);

	virtual std::string toString() const override;
	virtual bool isPrintable() const override;


	static bool toBool(std::string& str);

private:
	bool _var;
};