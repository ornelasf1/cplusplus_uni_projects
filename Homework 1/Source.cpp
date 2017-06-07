#include <iostream>
using namespace std;

int main()
{
	int array1[5] = { 1, 2, 3, 4, 5 };
	int array2[5];
	int counter = sizeof(array2[5]);

	for (int i = 0; i < 5; i++){
		cout << "Array1[" << i << "]: " << array1[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++){
		array2[i] = array1[counter];
		counter--;
		cout << "Array2[" << i << "]: " << array2[i] << endl;
	}
	system("pause");
	return 0;
}
