#pragma once
#include "Feline.h"
class Cat :
	public Feline
{
public:
	Cat();
	Cat(string cname);
	~Cat();
	string getName();
private:
	string name;
};

