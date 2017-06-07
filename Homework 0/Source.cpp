#include <iostream>
using namespace std;

int main()
{
	int fornumber;
	cout << "How many for loop run do you want?\n";
	cout << "Enter a number: ";
	cin >> fornumber;
	int forcount = 0;
	for (int i=0; i < fornumber; i++)
	{
		forcount++;
		cout << "For loop number: " << forcount << endl;
	}

	int whilenumber;
	cout << "\nHow many while loop run do you want?\n"
		<< "Enter a number: ";
	cin >> whilenumber;
	int whilecount = 1;
	while (whilenumber > 0)
	{
		cout << "While loop number: " << whilecount << endl;
		whilecount++;
		whilenumber--;
	}


	system("pause");
	return 0;
	
}