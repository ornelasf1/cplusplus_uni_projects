#include "cylinder.h"
#include <iostream>
using namespace std;

cylinder::cylinder()	//Default constructor sets height to 0
{
	h = 0;
}

cylinder::cylinder(float temp_r, float temp_h){	//Sets radius for circle private member
	setRadius(temp_r);
	h = temp_h;
}

cylinder::~cylinder()
{
}

float cylinder::area(){
	float temp_area = 2 * 3.1415926 * h * getRadius();
	return temp_area;
}

float cylinder::volume(){
	float temp_vol = 3.1415926 * h * (getRadius() * getRadius());
	return temp_vol;
}