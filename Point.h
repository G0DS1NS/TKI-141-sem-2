#pragma once
#include <iostream>

class Point
{
private:
	double x;
	double y;
public:
	double GetX();
	double GetY();
	bool operator==(Point& other);
	friend bool operator!=(Point& first, Point& second);
	friend std::istream& operator>>(std::istream& input, Point& other);
};