#include "Point.h"

double Point::GetX() const
{
    return x;
}

double Point::GetY() const
{
    return y;
}

bool Point::operator==(Point& other)
{
    return this->x == other.GetX() + std::numeric_limits<double>::epsilon() && this->y == other.GetY();
}

std::istream& Point::operator>>(std::istream& input)
{
    input >> this->x;
    input >> this->y;

    return input;
}


bool operator!=(Point& first, Point& second)
{
    return !(first == second);
}


