#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Student{
public:
	Student();
	~Student();
	vector<Student> allStudents;
	void input();
	void output();
	void reset();
private:
	string name;
	int numCourses;
	string * courseList;
};

//Student::Student(string getName, int getNumCourses)
Student::Student(){
}
Student::~Student(){
	courseList = NULL;
	delete[]courseList;
}

void Student::input(){
	fflush(stdin);
	cout << "Enter student name: ";
	getline(cin, name);
	fflush(stdin);
	cout << "Enter number of courses: ";
	cin >> numCourses;
	cin.ignore();
	courseList = new string[numCourses];
	for (int i = 0; i < numCourses; i++){
		cout << "Enter course " << i + 1 << ": " << endl;
		getline(cin, courseList[i]);
		cin.clear();
		fflush(stdin);
	}
	allStudents.push_back(*this);
}

void Student::output(){
	cout << "Number of students created: " << allStudents.size() << endl;
	for (int i = 0; i < allStudents.size(); i++){
		cout << "Student " << i + 1 << ": " << allStudents[i].name << endl;
		cout << "Courses: ";
		for (int j = 0; j < allStudents[i].numCourses; j++){
			cout << *(allStudents[i].courseList)++;
			if (j < allStudents[i].numCourses-1){
				cout << ", ";
			}
		}
		cout << endl << endl;
	}
}

void Student::reset(){
	numCourses = 0;
	courseList = NULL;
}

int main(){
	char ans;
	Student student;
	do{
		student.reset();
		student.input();
		cout << "Would you like to input a new student? <y/n>" << endl;
		cin >> ans;
	} while (ans == 'y');
	student.output();
	system("pause");
	return 0;
}