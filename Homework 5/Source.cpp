//1354098
//COSC 1430
//Fabian Ornelas
#include <iostream>
#include "circle.h"
#include "cylinder.h"
#include "point.h"
//Used multilevel inheritance to override functions that were set in the super class
using namespace std;

int main(){
	//circle object requires float radius
	circle cobj(3);
	//cylinder object requires float radius, and float height
	cylinder cylobj(3, 3);
	cout << "Area of the circle: " << cobj.area() << endl;
	cout << "Area of the cylinder: " << cylobj.area() << endl;
	cout << "Volume of cylinder: " << cylobj.volume() << endl;
	system("pause");
	return 0;
}