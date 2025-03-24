#include <iostream>
#include "Triangle.h"
#include <limits>

using namespace std;

double input_catheter(const string& message);

int main(void)
{
	double catheter1 = 0;
	double catheter2 = 0;
	catheter1 = input_catheter("Enter the len of first catheter: ");
	catheter2 = input_catheter("Enter the len of second catheter: ");
	Triangle triangle(catheter1, catheter2);
	cout << "Square: " << triangle.GetSquare() << endl;
	cout << "Radius: " << triangle.GetRadius() << endl;
	return 0;
}

double input_catheter(const string& message)
{
	double catheter;
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