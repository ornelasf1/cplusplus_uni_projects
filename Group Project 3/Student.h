#pragma once
class Student
{
public:
	Student();
	Student(int);
	~Student();
	friend void print(Student);
	int operator+(const Student&);
	friend int operator+(const int&, const Student&);
private:
	int studentID;
	int studentGrade;
};

