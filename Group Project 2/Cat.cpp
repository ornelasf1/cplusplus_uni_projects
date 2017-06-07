#include "Cat.h"


Cat::Cat()
{
	name = "cat";
}

Cat::Cat(string cname)
{
	name = cname;
}
Cat::~Cat()
{
}

string Cat::getName()
{
	return name;
}