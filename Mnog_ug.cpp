#include "Mnog_ug.h"

std::string Mnog::String(double number)
{
	std::stringstream ss;
	ss << number;
	std::string StringNumber = ss.str();
	return StringNumber;
}
