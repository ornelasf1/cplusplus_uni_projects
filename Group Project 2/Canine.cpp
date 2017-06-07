#include "Canine.h"

int Canine::count = 0;

Canine::Canine()
{
	count++;
}


Canine::~Canine()
{
	count--;
}

string Canine::speak(){
	return "Woof";
}