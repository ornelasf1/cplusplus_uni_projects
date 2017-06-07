#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int length(const char *a);

int main(){
	ifstream readFile;
	readFile.open("Text.txt");
	char output[100];
	char *words[9];
	char *t3[5], *t4[5], *t5[5];
	int count = 0;
	int t3_count = 0, t4_count = 0, t5_count = 0;

	if (!readFile.is_open()){
		cout << "File is not open." << endl;
	}

	while (readFile.is_open() && !readFile.eof()){
		readFile >> output;
		words[count] = new char[strlen(output) + 1];
		strcpy_s(words[count], 9, output);
		if (length(words[count]) == 3){
			t3[t3_count] = new char[length(words[count])];
			strcpy_s(t3[t3_count], length(words[count]) + 2, words[count]);
			t3_count++;
		}
		else if (length(words[count]) == 4){
			t4[t4_count] = new char[length(words[count])];
			strcpy_s(t4[t4_count], length(words[count]) + 2, words[count]);
			t4_count++;
		}
		else{
			t5[t5_count] = new char[length(words[count])];
			strcpy_s(t5[t5_count], length(words[count]) + 2, words[count]);
			t5_count++;
		}
		count++;
	}
	readFile.close();

	for (int i = 0; i < t3_count; i++){
		cout << t3[i] << endl;
		for (int j = 0; j < length(t3[i]); j++){
			cout << (t3[i])[j] << endl;
		}
		cout << endl;
	}

	for (int i = 0; i < t4_count; i++){
		cout << t4[i] << endl;
		for (int j = 0; j < length(t4[i]); j++){
			cout << (t4[i])[j] << endl;
		}
		cout << endl;
	}

	for (int i = 0; i < t5_count; i++){
		cout << t5[i] << endl;
		for (int j = 0; j < length(t5[i]); j++){
			cout << (t5[i])[j] << endl;
		}
		cout << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}

int length(const char *a){
	int count = 0;
	while (*a != 0){
		*(a++);
		count++;
	}
	return count;
}