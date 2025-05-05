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


bool operator!=(Point& first, Point& second)
{
    return !(first == second);
}

std::istream& operator>>(std::istream& input, Point& other)
{
    input >> other.x >> other.y;
    return input;
}
