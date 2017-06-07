#include "Dog.h"


Dog::Dog()
{
	name = "dog";
}

Dog::Dog(string dname){
	name = dname;
}

Dog::~Dog()
{
}

string Dog::getName(){
	return name;
}
