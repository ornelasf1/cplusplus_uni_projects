//Fabian Ornelas - Homework 2
//1354098
#include <iostream>
using namespace std;
void setArray(int array[], int number, int arraySize);
void printArray(int array1[], int array2[]);

int main(){
	//Declared pointers.
	int *a_ptr, *b_ptr;
	//Dynamically allocated 20 elements to a_ptr
	a_ptr = new int[20];
	//Declared and initialized random to integer types.
	int randA = rand() % 40 + 20;
	int randB = rand() % 90 + 70;
	//Used setArray twice to assign for arrayA twice.
	setArray(a_ptr, randA, 20);
	b_ptr = a_ptr;
	a_ptr = new int[20];
	setArray(a_ptr, randB, 20);

	printArray(a_ptr, b_ptr);
	cout << sizeof(b_ptr) << endl;
	system("pause");
	delete[] a_ptr;
	delete[] b_ptr;
	a_ptr = NULL;
	b_ptr = NULL;
}

void setArray(int array[], int number, int arraySize){
	for (int i = 0; i < arraySize; i++){
		array[i] = number++;
	}
}

void printArray(int array1[], int array2[]){
	for (int i = 0; i < 20; i++){
		cout << "ArrayA[" << i << "]: " << array1[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < 20; i++){
		cout << "ArrayB[" << i << "]: " << array2[i] << endl;
	}
}