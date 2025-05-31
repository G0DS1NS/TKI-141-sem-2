#include "TestFramework.h"

void RunTest(TestCase* test)
{
	std::cout << "Running test: " << test->name << std::endl;
	if (test->run())
	{
		std::cout << "Passed" << std::endl;
	}
	else
	{
		std::cout << "Failed" << std::endl;
	}
}
