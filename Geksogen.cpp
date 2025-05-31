#include <cmath>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <limits>
#include "Geksogen.h"
#include "Point.h"


double Geksogen::GetLen(Point& point1, Point& point2)
{
	return sqrt(pow(point2.GetX() - point1.GetX(), 2) + pow(point2.GetY() - point1.GetY(), 2));
}



bool Geksogen::IsRightGeksogen()
{
	for (size_t i = 0; i < lens.size(); i++)
	{
		if (lens[i] != lens[i + 1])
		{
			return false;
		}
	}

	return true;
}

Geksogen::Geksogen(std::vector<Point> points)
{
	this->list_points = points;
	for (size_t i = 0; i < list_points.size() - 1; i++)
	{
		this->lens.push_back(GetLen(list_points[i], list_points[i + 1]));
		if (lens[lens.size() - 1] < std::numeric_limits<double>::epsilon())
		{
			throw std::invalid_argument("Your input is uncorrected");
		}
	}

}

Geksogen::Geksogen(std::vector<double> list)
{
	this->lens = list;
	for (size_t i = 0; i < lens.size() - 1; i++)
	{
		if (lens[i] < std::numeric_limits<double>::epsilon() && lens[i] != lens[i + 1] + std::numeric_limits<double>::epsilon())
		{
			throw std::invalid_argument("Error");
		}
	}
}

double Geksogen::GetRadius()
{
	return lens[0];
}

double Geksogen::GetSquare()
{
	return (3 * sqrt(3) * pow(lens[0], 2) / 2);
}

double Geksogen::GetPerimeter()
{
	return lens[0] * 6;
}



 
