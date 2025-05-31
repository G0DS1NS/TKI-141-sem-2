#pragma once
#include <vector>
#include <fstream>
#include <memory>
#include "Mnog_ug.h"
#include "Point.h"

class Geksogen : public Mnog
{
private:
	std::vector<double> lens;
	std::vector<Point> list_points;
	double GetLen(Point& point1, Point& point2);
	bool IsRightGeksogen();
public:
	Geksogen(std::vector<Point> points);
	Geksogen(std::vector<double> list);
	double GetRadius() override;
	double GetSquare() override;
	double GetPerimeter() override;
};
