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

	Car* cars = nullptr;
	int AllocationSize, numCars, carArraySize;

	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry\n";
		cout << "Enter the data in the following format:\n";
		cout << "Make and model,LicensePlate,MilitaryTime<ENTER>\n";
		cout << "Exit the program by entering the following:\n";
		cout << "X, <ENTER>" << endl;
	}

	void initialize(int allocSize) {

		numCars = 0;
		AllocationSize = carArraySize = allocSize;
		cars = new Car[AllocationSize];
	}

	void deallocate(Car& C) {
		delete[] C.makeAndModel;
		C.makeAndModel = nullptr;
	}

	bool read(Car& C) {

		bool done = false;
		char makeAndModel[MAX_CSTRING];
		char time[4];

		read(makeAndModel, MAX_CSTRING, ',');

		if (strCmp(makeAndModel, "X") != 0)
		{
			int length = strLen(makeAndModel) + 1;
			C.makeAndModel = new char[length];
			strCpy(C.makeAndModel, makeAndModel);
			done = true;

			read(C.licencePlate, MAX_CHAR, ',');

			read(time, 4);
			C.time = atoi(time);
		}

		return done;
	}

	void print(const Car& C) {

		cout << C.time << ": " << C.makeAndModel << "," << C.licencePlate << endl;
	}

	void record(const Car& C) {

		if (numCars == carArraySize)
		{
			Car* temp = new Car[carArraySize + AllocationSize];
			for (int j = 0; j < carArraySize; j++)
			{
				strCpy(temp[j].licencePlate, cars[j].licencePlate);
				temp[j].makeAndModel = cars[j].makeAndModel;
				temp[j].time = cars[j].time;
			}
			delete[] cars;
			cars = temp;
			carArraySize += AllocationSize;
		}

		strCpy(cars[numCars].licencePlate, C.licencePlate);
		cars[numCars].makeAndModel = C.makeAndModel;
		cars[numCars].time = C.time;
		numCars += 1;
	}

	void endOfDay() {

		for (int i = 0; i < numCars; i++)
		{
			print(cars[i]);
			deallocate(cars[i]);
		}
		delete[] cars;
		cars = nullptr;
	}
}