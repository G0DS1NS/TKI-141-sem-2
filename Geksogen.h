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
	std::vector<Point> points();
	std::vector<Point> list_points;
	double GetLen(Point& point1, Point& point2);
public:
	Geksogen();
	void Geksogen_with_len();
	void Geksogen_with_point();
	double GetRadius() override;
	double GetSquare() override;
	double GetPerimeter() override;
	friend std::istream& operator>>(std::istream& input, Geksogen& fig);
};