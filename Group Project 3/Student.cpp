#include "Student.h"
#include <random>
Student::Student(){
}

Student::Student(int tempID)
{
	int tempGrade = rand() % 101;
	studentGrade = tempGrade;
	studentID = tempID;
}


Student::~Student()
{
}

int Student::operator+(const Student& next){
	int temp;
	temp = this->studentGrade + next.studentGrade;
	return temp;
}

int operator+(const int& first, const Student& next) {
	int temp;
	temp = first + next.studentGrade;
	return temp;
}
