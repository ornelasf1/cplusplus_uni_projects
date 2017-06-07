#include <iostream>
#pragma once
class point
{
public:
	point();
	point(int, int);	//Declared a constructor that will receive for x and y
	~point();
	virtual float area() = 0;	//Created a pure virtual function so it can be overriden in its child files
private:
	float x, y;
};

