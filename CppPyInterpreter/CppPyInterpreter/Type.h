#pragma once
#include <string>

class Type
{
public:
	Type();
	Type(bool isTemp);

	bool getIsTemp() const;
	void setIsTemp(const bool& isTemp);

	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;

private:
	bool _isTemp;
};
