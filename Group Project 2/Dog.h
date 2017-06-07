#pragma once
#include "Canine.h"
class Dog :
	public Canine
{
public:
	Dog();
	Dog(string dname);
	~Dog();
	string getName();
private:
	string name;
};

