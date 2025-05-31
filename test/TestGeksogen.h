#pragma once
#include "Geksogen.h"
#include "TestFramework.h"

class GeksogenGetPerimeterTestLen : TestCase
{
public:
	GeksogenGetPerimeterTestLen();
	bool run() override;
};

class GeksogenGetPerimeterTestPoint : TestCase
{
public:
	GeksogenGetPerimeterTestPoint();
	bool run() override;
};

class GeksogenGetRadiusTestPoint : TestCase
{
public:
	GeksogenGetRadiusTestPoint();
	bool run()  override;
};

class GeksogenGetRadiusTestLen : TestCase
{
public:
	GeksogenGetRadiusTestLen();
	bool run() override;
};

class GeksogenGetSquareTestPoint : TestCase
{
public: 
	GeksogenGetSquareTestPoint();
	bool run() override;
};

class GeksogenGetSquareTestLen : TestCase
{
public:
	GeksogenGetSquareTestLen();
	bool run() override;
};

void RunGeksogenTest();
