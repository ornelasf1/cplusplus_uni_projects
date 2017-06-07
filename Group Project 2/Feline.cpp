#include "Feline.h"

int Feline::count = 0;

Feline::Feline()
{
	count++;
}


Feline::~Feline()
{
	count--;
}

string Feline::speak(){
	return "Purr";
}