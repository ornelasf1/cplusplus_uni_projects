#include "circle.h"
#include <iostream>
#include <cmath>
using namespace std;
circle::circle(){	//By default, radius is set to 0 if nothing is passed
	r = 0;
}

circle::circle(float r_temp)
{
	r = r_temp;
}

circle::~circle()
{
}

float circle::getRadius(){	//Defined function to be used in child classes
	return r;
}

void circle::setRadius(float r_temp){	//Defined function to be used in classes
	r = r_temp;
}

float circle::area(){
	float temp_area;
	temp_area = 3.1415926 * (r * r);	//Area of circle is pi*r^2
	return temp_area;
}