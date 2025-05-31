#pragma once
#include "TestFramework.h"

class TestGetXPoint: TestCase
{
public:
	
	TestGetXPoint();
	bool run() override;
};

class TestGetYPoint : TestCase
{
public:
	TestGetYPoint();
	bool run() override;
};

class TestEqualityPoint : TestCase
{
public:
	TestEqualityPoint();
	bool run() override;
};

class TestInequalityPoint : TestCase
{
public:
	TestInequalityPoint();
	bool run() override;
};

void RunTestPoint();
