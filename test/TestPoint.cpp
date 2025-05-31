#include <sstream>
#include<cmath>
#include "TestPoint.h"
#include "Point.h"

TestGetXPoint::TestGetXPoint()
{
	name = "Point GetX Test";
}

bool TestGetXPoint::run()
{
	Point p;
	std::istringstream iss("1.0 3.0");
	p >> iss;
	ASSERT(fabs(p.GetX()) - std::numeric_limits<double>::epsilon(), "GetX Error");
	return true;
}

TestGetYPoint::TestGetYPoint()
{
	name = "Point GetY Test";
}

bool TestGetYPoint::run()
{
	Point p;
	std::istringstream iss("1.0 3.0");
	p >> iss;
	ASSERT(fabs(p.GetX()) - std::numeric_limits<double>::epsilon(), "GetY Error");
	return true;
}

TestEqualityPoint::TestEqualityPoint()
{
	name = "Point Equality test";
}

bool TestEqualityPoint::run()
{
	Point p1;
	Point p2;
	std::istringstream iss1("1.0 3.0");
	std::istringstream iss2("1.0 3.0");
	p1 >> iss1;
	p2 >> iss2;
	ASSERT(p1 == p2, "Point Equality Error");
	return true;
}

TestInequalityPoint::TestInequalityPoint()
{
	name = "Point Inquality test";
}

bool TestInequalityPoint::run()
{
	Point p1;
	Point p2;
	std::istringstream iss1("1.0 3.0");
	std::istringstream iss2("1.0 3.0");
	p1 >> iss1;
	p2 >> iss2;
	ASSERT(p1 != p2, "Point Inequality Error");
	return true;
}

void RunTestPoint()
{
	RunTest(new TestGetXPoint());
	RunTest(new TestGetYPoint());
	RunTest(new TestEqualityPoint());
	RunTest(new TestInequalityPoint());
}
