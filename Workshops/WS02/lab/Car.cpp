/* ------------------------------------------------------
OOP244 NAA
Workshop 2 part 1
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/01/29
-----------------------------------------------------------*/
// All function prototypes are provided by the professor Fardad Soleimanloo
#include <iostream>
#include <cstdlib>
#include "Car.h"
#include "cStrTools.h"
using namespace std;

namespace sdds {
	
	const int MAX_CSTRING = 60 + 1;
	Car* cars = nullptr;
	int allocationSize, numCars, carArrSize;

	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry\n";
		cout << "Enter the data in the following format:\n";
		cout << "Make and model,LicensePlate,MilitaryTime<ENTER>\n";
		cout << "Exit the program by entering the following:\n";
		cout << "X, <ENTER>" << endl;
	}

	void initialize(int allocSize) {
		numCars = 0;
		carArrSize = allocationSize = allocSize;
		cars = new Car[allocationSize];
	}

	void deallocate(Car& C) {
		delete[] C.makeAndModel;
		C.makeAndModel = nullptr;
	}

	bool read(Car& C) {
		bool done = false;
		char makeAndModel[MAX_CSTRING];
		char time[4 + 1];

		read(makeAndModel, MAX_CSTRING, ',');
		if (strCmp(makeAndModel, "X") != 0)
		{
			done = true;
			int length = strLen(makeAndModel) + 1;
			C.makeAndModel = new char[length];
			strCpy(C.makeAndModel, makeAndModel);
			read(C.licensePlate, MAX_CHAR, ',');
			read(time, 4 + 1);
			C.time = atoi(time);
		}
		return done;
	}

	void print(const Car& C) {
		cout << C.time << ": " << C.makeAndModel << "," << C.licensePlate << endl;
	}

	void record(const Car& C) {

		if (numCars == carArrSize)
		{
			Car* temp = new Car[carArrSize + allocationSize];
			for (int i = 0; i < carArrSize; i++)
			{
				strCpy(temp[i].licensePlate, cars[i].licensePlate);
				temp[i].makeAndModel = cars[i].makeAndModel;
				temp[i].time = cars[i].time;
			}
			delete[] cars;
			cars = nullptr;
			cars = temp;
			carArrSize += allocationSize;
						
		}
		strCpy(cars[numCars].licensePlate, C.licensePlate);
		cars[numCars].makeAndModel = C.makeAndModel;
		cars[numCars].time = C.time;
		numCars += 1;
	}

	void endOfDay() {
		for (int i = 0; i < carArrSize; i++)
		{
			print(cars[i]);
			deallocate(cars[i]);
		}
		delete[] cars;
		cars = nullptr;
	}

}