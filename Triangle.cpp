#include <cmath>
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

Triangle::Triangle(double catheter1, double catheter2) :
	catheter1{ catheter1 }, catheter2{ catheter2 }, hypotenuse{ GetHypotenuse() }
{

}