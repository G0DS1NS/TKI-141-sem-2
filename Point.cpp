#include "Point.h"

double Point::GetX()
{
    return x;
}

double Point::GetY()
{
    return y;
}

bool Point::operator==(Point& other)
{
    return this->x == other.GetX() && this->y == other.GetY();
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
