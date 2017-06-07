#pragma once
#include "Animal.h"
class Feline :
	public Animal
{
public:
	Feline();
	~Feline();
	string speak();
	static int count;
};

	