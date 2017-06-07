// Group 16 
// COSC 1430
// Guoning Chen
#include <iostream>
#include "Animal.h"
#include "Canine.h"
#include "Feline.h"
#include "Dog.h"
#include "Cat.h"
#include "Wolf.h"
using namespace std;

int main(){
	Animal *ani_obj;	//Does not instantiate, only used to point to instances in class
	Dog *dobj = new Dog("Larry the Dog"); //Creates pointer objects and allocates mem with their respective type.
	Wolf *wobj = new Wolf; 
	Cat *cobj = new Cat("Jingles the Cat");
	Animal * animals[3];	//Stores pointer objects to the dynamic array
	animals[0] = dobj;
	animals[1] = wobj;
	animals[2] = cobj;

	for (int i = 0; i < 3; i++){
		cout << animals[i]->speak() << endl;	//Uses pointer notation to access members
	}
	cout << wobj->howl() << endl;
	cout << "Animals: " << ani_obj->count << endl;
	cout << "Canine: " << dobj->count << endl;
	cout << "Feline: " << cobj->count << endl;
	system("pause");
	return 0;
	delete ani_obj, dobj, wobj, cobj;
	delete[] animals;
}