#include "TestGeksogen.h"

GeksogenGetPerimeterTestLen::GeksogenGetPerimeterTestLen()
{
	name = "Geksogen GetPerimeter Test for Len";
}

bool GeksogenGetPerimeterTestLen::run()
{
    std::vector<double> l(5.0, 6);
    std::vector<double> lens = l;
    Geksogen g(lens);
    ASSERT(fabs(g.GetPerimeter() - 30.0) < std::numeric_limits<double>::epsilon(),
        "Perimeter should be 6 * side length");
    return true;
}

GeksogenGetPerimeterTestPoint::GeksogenGetPerimeterTestPoint()
{
    name = "Geksogen GetPerimeter Test for Point";
}

bool GeksogenGetPerimeterTestPoint::run()
{
    std::vector<Point> points(6);
    std::vector<std::stringstream> iss_full = { std::stringstream("5.0 0"), std::stringstream("2.5 4.33"), std::stringstream("-2.5 4.33"), std::stringstream("-5 0"), std::stringstream("-2.5 -4.33"), std::stringstream("2.5 -4.33") };
    
    for (size_t i = 0; i < 6; i++)
    {
        iss_full[i] >> points[i];
    }

    Geksogen g(points);

    ASSERT(fabs(g.GetPerimeter() - 30) < std::numeric_limits<double>::epsilon(), "Perimeter should be 6 * Point");
    return true;
}

GeksogenGetRadiusTestPoint::GeksogenGetRadiusTestPoint()
{
    name = "Geksogen GetRadius test for Point";
}

bool GeksogenGetRadiusTestPoint::run()
{
    std::vector<Point> points(6);
    std::vector<std::stringstream> iss_full = { std::stringstream("5.0 0"), std::stringstream("2.5 4.33"), std::stringstream("-2.5 4.33"), std::stringstream("-5 0"), std::stringstream("-2.5 -4.33"), std::stringstream("2.5 -4.33") };

    for (size_t i = 0; i < 6; i++)
    {
        iss_full[i] >> points[i];
    }

    Geksogen g(points);

    ASSERT(fabs(g.GetRadius() - 5) < std::numeric_limits<double>::epsilon(), "GetRadius for Point Error");
    return true;
}

GeksogenGetRadiusTestLen::GeksogenGetRadiusTestLen()
{
    name = "Geksogen GetRadius test for len";
}

bool GeksogenGetRadiusTestLen::run()
{
    std::vector<double> l(5.0, 6);
    std::vector<double> lens = l;
    Geksogen g(lens);
    ASSERT(fabs(g.GetRadius() - 5) < std::numeric_limits<double>::epsilon(),
        "GetRadius for Point Error");
    return true;
}

GeksogenGetSquareTestPoint::GeksogenGetSquareTestPoint()
{
    name = "Geksogen GetSquare test for point";
}

bool GeksogenGetSquareTestPoint::run()
{
    std::vector<Point> points(6);
    std::vector<std::stringstream> iss_full = { std::stringstream("5.0 0"), std::stringstream("2.5 4.33"), std::stringstream("-2.5 4.33"), std::stringstream("-5 0"), std::stringstream("-2.5 -4.33"), std::stringstream("2.5 -4.33") };

    for (size_t i = 0; i < 6; i++)
    {
        iss_full[i] >> points[i];
    }

    Geksogen g(points);

    ASSERT(fabs(g.GetSquare() - 37.5 * sqrt(3)) < std::numeric_limits<double>::epsilon(), "GetSquare for point Error");

    return true;
}

GeksogenGetSquareTestLen::GeksogenGetSquareTestLen()
{
    name = "Geksogen GetSquare test for len";
}

bool GeksogenGetSquareTestLen::run()
{
    std::vector<double> l(5.0, 6);
    std::vector<double> lens = l;
    Geksogen g(lens);

    ASSERT(fabs(g.GetSquare() - 37.5 * sqrt(3)) < std::numeric_limits<double>::epsilon(), "GetSquare for len Error");

    return true;
}

void RunGeksogenTest()
{
    puts("===Run Geksogen Test===");
    RunTest(new GeksogenGetPerimeterTestLen());
    RunTest(new GeksogenGetPerimeterTestPoint());
    RunTest(new GeksogenGetRadiusTestPoint());
    RunTest(new GeksogenGetRadiusTestLen());
    RunTest(new GeksogenGetSquareTestPoint());
    RunTest(new GeksogenGetSquareTestLen());
}