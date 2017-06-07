//Fabian Ornelas
//1354098
//COSC 1430 - Tues:11:30am - 1am
#include <iostream>
#include <fstream>
using namespace std;
void decrypt(char charsArray[], int loops);

int main(){
	ifstream file;
	file.open("hw3_encrypted.txt");
	if (file.fail()){
		cout << "The file \"hw3_encrypted.txt\" was unable to open." << endl;
	}

	char array[200] = {};
	char c;
	int count = 0;
	if (file.is_open()){
		while (file.get(c)){
			array[count] = c;
			count++;
		}
	}
	file.close();
	decrypt(array, count);
	system("pause");
	return 0;
}

void decrypt(char charsArray[], int loops){
	ofstream writeFile;
	writeFile.open("message.txt");
	int temp = 0;
	char newArray[200] = {};
	while (temp < loops){
		char c = charsArray[temp];
		switch (c){
		case '1':
			c = 'a';
			newArray[temp] = c;
			break;
		case '2':
			c = 'e';
			newArray[temp] = c;
			break;
		case '3':
			c = 'i';
			newArray[temp] = c;
			break;
		case '4':
			c = 'o';
			newArray[temp] = c;
			break;
		case '5':
			c = 'u';
			newArray[temp] = c;
			break;
		case '6':
			c = ' ';
			newArray[temp] = c;
			break;
		default:
			newArray[temp] = c;
			break;
		}
		temp++;
	}
	writeFile << newArray;
	writeFile.close();
	cout << newArray << endl;
	cout << "File has been decrypted and stored in \"message.txt\"." << endl;
}