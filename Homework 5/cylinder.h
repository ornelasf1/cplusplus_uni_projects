#pragma once
#include "circle.h"
class cylinder :
	public circle
{
public:
	cylinder();
	cylinder(float, float);	//Declared a constructor with parameters to input for radius and this class' height.
	~cylinder();
	float area();	//Overriden function that does calculates area of cylinder
	float volume();	//New function that calculates volume of cylinder
private:
	float h;
};

