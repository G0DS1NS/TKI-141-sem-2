#include <cmath>
#include <stdexcept>
#include "Triangle.h"

double Triangle::GetHypotenuse()
{
	return sqrt(pow(catheter1, 2) + pow(catheter2, 2));
}

double Triangle::GetSquare()
{
	return (catheter1 * catheter2) / 2;
}

double Triangle::GetRadius()
{
	return catheter1 / (catheter2 / hypotenuse);
}

Triangle::Triangle(double catheter1, double catheter2) 
{
	if(catheter1 <= numeric_limits<double>::epsilon() || catheter2 <= numeric_limits<double>::epsilon())
	{
		throw invalid_argument("Negative value not allowes");
	}
	this->catheter1 = catheter1;
	this->catheter2 = catheter2;
}
