#include <iostream>
#include "Student.h"
using namespace std;

void print(Student temp){
	cout << "Student " << temp.studentID << ": Grade " << temp.studentGrade << endl;
}

int avgOf2(Student a, Student b){
	return (a + b) / 2;
}

int avgOf3(Student a, Student b, Student c){
	int temp;
	temp = a + b;
	return (temp + c) / 3;
}

int avgOf4(Student a, Student b, Student c, Student d){
	int temp;
	temp = a + b + c;
	return (temp + d) / 4;
}

int main(){
	int numOfStudents, groupSize, numOfGroups;
	Student *listOfStudents;	//Dynamic array of student objects
	cout << "Enter the number of students: " << endl;
	cin >> numOfStudents;
	listOfStudents = new Student[numOfStudents];	//Initialize amount of students user specified
	try{
		cout << "Enter the number of students in each of group: " << endl;
		cin >> groupSize;
		cout << "---" << endl;
		if ((numOfStudents % groupSize) != 0){	//If the number of students is 
			//divisble by the specified group size, then continue, otherwise throw an exception
			throw groupSize;
		}
		numOfGroups = numOfStudents / groupSize;	//Stores nummber of groups will be created

		for (int i = 0; i < numOfStudents; i++){
			Student* temp = new Student(i + 1);	//Adds a student object with initialized values 
			//to a slot in the dynamic array
			listOfStudents[i] = *temp;
			delete temp;
		}
		int count = 0;
		for (int i = 0; i < numOfGroups; i++){
			for (int j = 0; j < groupSize; j++, count++){	//Loop through all the group and every group
				print(listOfStudents[count]);
				if (j == 1 && groupSize == 2){	//If it's divisble by 2, then print the following.
					cout << "Group Average = " << avgOf2(listOfStudents[count - 1], listOfStudents[count]) << endl;;
				}
				else if(j == 2 && groupSize == 3){
					cout << "Group Average = " << avgOf3(listOfStudents[count - 2], 
						listOfStudents[count-1], listOfStudents[count]) << endl;
				}
				else if (j == 3 && groupSize == 4){
					cout << "Group Average = " << avgOf4(listOfStudents[count - 3], listOfStudents[count - 2],
						listOfStudents[count - 1], listOfStudents[count]) << endl;
				}
			}

			cout << endl;
		}
	}
	catch (...){
		cout << "ERROR: CANNOT SPLIT STUDENTS EVENLY INTO GROUPS" << endl;
	}
	system("pause");
	delete[] listOfStudents;
	return 0;
}