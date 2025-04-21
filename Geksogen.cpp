#include <cmath>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <float.h>
#include "Geksogen.h"
#include "Point.h"

std::vector<Point> Geksogen::points()
{
	std::vector<Point> list_points;
	bool flag = false;
	Point point;
	for (size_t i = 0; i < 6; ++i)
	{
		std::cin >> point;
		if (flag)
		{
			if (point == list_points[list_points.size() - 1])
			{
				throw std::invalid_argument("Your input is uncorrected");
			}
			list_points.push_back(point);
		}
		else
		{
			list_points.push_back(point);
			flag = true;
		}
	}

	return list_points;
}

double Geksogen::GetLen(Point& point1, Point& point2)
{
	return sqrt(pow(point2.GetX() - point1.GetX(), 2) + pow(point2.GetY() - point1.GetY(), 2));
}

Geksogen::Geksogen()
{
	try
	{
		std::cin >> *this;
	}
	catch(std::runtime_error)
	{
		exit(1);
	}

}

void Geksogen::Geksogen_with_len()
{
	double len = 0;
	for (size_t i = 0; i < lens.size(); i++)
	{
		std::cin >> len;
		if (len < DBL_EPSILON)
		{
			throw std::invalid_argument("Your input is uncorrected");
		}
		this->lens.push_back(len);
	}
}


void Geksogen::Geksogen_with_point()
{
	list_points = points();
	for (size_t i = 0; i < list_points.size() - 1; i++)
	{
		this->lens.push_back(GetLen(list_points[i], list_points[i + 1]));
		if (lens[lens.size() - 1] < DBL_EPSILON)
		{
			throw std::invalid_argument("Your input is uncorrected");
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

std::istream& operator>>(std::istream& input, Geksogen& fig)
{
	typedef enum
	{
		with_len = 1,
		with_point
	}choose;
	std::cout << "Enter the your choose: " << std::endl;
	int ch_number = 0;
	input >> ch_number;
	try
	{
		switch ((choose)ch_number)
		{
		case with_len:
		{
			fig.Geksogen_with_len();
			break;
		}
		case with_point:
		{
			fig.Geksogen_with_point();
			break;
		}
		default:
		{
			throw std::invalid_argument("Error");
		}
		}
	}
	catch (std::invalid_argument)
	{
		throw std::runtime_error("Error");
	}

	return input;

}
