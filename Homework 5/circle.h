#pragma once
#include "point.h"
class circle :
	public point
{
public:
	circle();
	circle(float);	//Declared constructor that receives a radius and edits private member
	~circle();
	float area();
	float getRadius();
	void setRadius(float);
private:
	float r;
};