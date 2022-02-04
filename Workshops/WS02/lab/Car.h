/* ------------------------------------------------------
OOP244 NAA
Workshop 2 part 1
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/01/29
-----------------------------------------------------------*/
// All function prototypes are provided by the professor Fardad Soleimanloo
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

namespace sdds{
	
	const int MAX_CHAR = 8 + 1; // + 1 for the null terminator

	struct Car {
		char licensePlate[MAX_CHAR];
		char* makeAndModel;
		int time;
	};

	void VBPLE_Title();
	void initialize(int allocSize);
	void deallocate(Car& C);
	bool read(Car& C);
	void print(const Car& C);
	void record(const Car& C);
	void endOfDay();
}


#endif // !SDDS_CAR_H

