#pragma once

class Triangle
{
private:
	double catheter1;
	double catheter2;
	double hypotenuse;
	double GetHypotenuse();
public:
	Triangle(double catheter1, double catheter2);
	double GetSquare();
	double GetRadius();
};
