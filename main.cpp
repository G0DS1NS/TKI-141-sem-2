#include <iostream>
#include <stdexcept>
#include <limits>
#include "Triangle.h"


using namespace std;

double input_catheter(const string& message);

int main(void)
{
	double catheter1 = input_catheter("Enter the len of first catheter: ");
	double catheter2 = input_catheter("Enter the len of second catheter: ");
	try{
		Triangle triangle(catheter1, catheter2);
	}catch(const exception& e)
		{
			cout << "Invalid argument" << endl;
			return 1;
		}
	cout << "Square: " << triangle.GetSquare() << endl;
	cout << "Radius: " << triangle.GetRadius() << endl;
	return 0;
}

double input_catheter(const string& message)
{
	double catheter = 0;
	while (true)
	{
		cout << message << endl;
		cin >> catheter;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input is uncorrected. Try again!";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return catheter;
	}

}
