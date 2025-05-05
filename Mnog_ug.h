#pragma once

#include <iostream>
#include <sstream>
#include <string>

class Mnog
{
public:
	virtual double GetSquare() = 0;
	virtual double GetPerimeter() = 0;
	virtual double GetRadius() = 0;
	virtual void initialize_obj() = 0;
	virtual std::string String(double number);
	virtual ~Mnog();
};
