#pragma once
#include "Sequence.h"

class String : public Sequence
{
public:
	String(std::string stringValue);

	std::string getVar() const;
	void SetVar(std::string stringValue);

	virtual std::string toString() const override;
	virtual bool isPrintable() const override;

private:
	std::string _var;
};