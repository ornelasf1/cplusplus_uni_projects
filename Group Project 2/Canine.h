#pragma once
#include "Animal.h"
class Canine :
	public Animal
{
public:
	Canine();
	~Canine();
	string speak();
	static int count;
};

