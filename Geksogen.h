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
	std::istream& operator>>(std::istream& input);
	void Geksogen_with_len();
	void Geksogen_with_point();
public:
	Geksogen();
	void initialize_obj() override;
	double GetRadius() override;
	double GetSquare() override;
	double GetPerimeter() override;
};
