//Fabian Ornelas - HomeWork 6
// 1354098
// COSC 1430
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct RepairList{
	int repairCode;
	string repairPart;
};

class CarLot{
public:	//Mutators, accessors, destructor, and constructor
	CarLot(){ numOfCars++; repairSize = 0; };	//Adds 1 to the number of cars based on number of objects 
													//and initializes repairSize to 0.
	~CarLot(){ numOfCars--; };
	void setModel(string);	//Takes a string argument to modify model pvt variable
	string getModel();		//Returns model
	int getRepairSize();	
	void addRepairSize();
	void setRepairs(int);	//Mutator that will increase the size of the dynamic array dependent on the number
								//of repairs an object has.
	int *getRepairs();
private:
	string model;
	int repairSize;
	int* repairs = NULL;
	static int numOfCars;
};

int* CarLot::getRepairs(){
	return repairs;
}

int CarLot::getRepairSize(){
	return repairSize;
}

void CarLot::setRepairs(int x){
	if (repairs == NULL){	//If repairs has yet to be allocated any memory, then run this.
		repairs = new int[repairSize];	//Allocate memory
		for (int i = 0; i < repairSize; i++){	//Assing argument to the iteration. Function is used in loop
			repairs[i] = x;
		}
	}
	else{	//If repairs does have memory allocated to it, then run this.
		int *temp = new int[repairSize];	//Creates temporary int array that will hold the values.
		for (int i = 0; i < repairSize; i++){
			temp[i] = repairs[i];
		}
		delete[] repairs;	//Delete original array and reallocate array based on the new repairSize
		repairs = new int[repairSize];
		for (int i = 0; i < repairSize; i++){	//Pass values from temp to original now with an extra slot.
			repairs[i] = temp[i];
		}
		delete[] temp;
		repairs[repairSize - 1] = x;
	}
}

void CarLot::addRepairSize(){
	repairSize++;
}

void CarLot::setModel(string name){
	model = name;
}

string CarLot::getModel(){
	return model;
}

int CarLot::numOfCars = 0;

int main(){
	vector<RepairList> repairList;	//Holds list of objects.
	char firstElem = ' ';
	string line;
	ifstream repFile;
	repFile.open("RepairsKey.txt");

	if (repFile.is_open()){
		while (!repFile.eof()){	//Checks every line and stores it in string line.
			getline(repFile, line);
			firstElem = line[0];	//Retrieves first element and stores.
			RepairList repair;
			repair.repairCode = firstElem - 48;	//Stores the first element minus 48 (from ASCII representation)
			repair.repairPart = line.substr(2); //Gets string from 2nd element to the end of it.
			repairList.push_back(repair);
		}
	}
	repFile.close();

	vector<CarLot> lotOfCars;
	char letter;
	line = "";
	ifstream carFile;
	carFile.open("Cars.txt");
	if (carFile.is_open()){
		while (!carFile.eof()){
			CarLot *vehicle = new CarLot;	//Allocates memory to vehicle object
			getline(carFile, line);
			int sizeOfWord = 0;
			for (int i = 0; i < line.length(); i++){
				if ((line[i] == ' ') && (sizeOfWord == 0)){	//Identifies when the first space 
																//is reached to split it from the rest of the line to get name.
					sizeOfWord = i;
				}
				if (i > sizeOfWord && sizeOfWord != 0 && line[i] != ' '){ //Identifies spaces after the first 
																			//to attain the repairCodes.
					vehicle->addRepairSize();
					vehicle->setRepairs(line[i]-48);
				}
			}
			vehicle->setModel(line.substr(0, sizeOfWord));
			lotOfCars.push_back(*vehicle);
		}
	}
	carFile.close();

	for (int i = 0; i < lotOfCars.size(); i++){
		cout << "Car Model: " << lotOfCars[i].getModel() << endl;
		for (int j = 0; j < lotOfCars[i].getRepairSize(); j++){
			try{
				for (int k = 0; k < repairList.size(); k++){
					if (lotOfCars[i].getRepairs()[j] == repairList[0].repairCode){
						throw repairList[0].repairCode;
					}
					if (lotOfCars[i].getRepairs()[j] == repairList[k].repairCode){
						cout << "Repair #" << j + 1 << ": ";
						cout << repairList[k].repairPart << endl;
					}
				}
			}
			catch (int e){
				cout << "Pass: Car is done" << endl;
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}