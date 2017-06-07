#include "Animal.h"

int Animal::count = 0;	//Initialize the static variable
Animal::Animal()
{
	count++;	//Increments the static count by 1
}

Animal::~Animal()
{
	count--;
}

