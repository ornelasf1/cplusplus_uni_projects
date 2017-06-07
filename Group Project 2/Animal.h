#include <iostream>
#include <string>
using namespace std;
#pragma once
class Animal	//base class
{
public:
	//Constructor/Destructor
	Animal();	// define this in cpp
	~Animal();	// define this in cpp
	virtual string speak() = 0;		//Declares a pure virtual function
	static int count;	//Declares the static variable
};

