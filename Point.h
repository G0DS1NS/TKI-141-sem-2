#pragma once
#include <iostream>
#include <limits>

class Point
{
private:
	double x;
	double y;
public:
	double GetX() const;
	double GetY() const;
	bool operator==(Point& other);
	std::istream& operator>>(std::istream& input);
};

bool operator!=(Point& first, Point& second);
