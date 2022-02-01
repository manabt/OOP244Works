/* ------------------------------------------------------
OOP244 NAA
Workshop 2 part 1
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/01/29
-----------------------------------------------------------*/
// All function prototypes are provided by the professor Fardad Soleimanloo
#ifndef SDDS_CAR_H
#define SDDS_CAR_H


namespace sdds {

	const int MAX_CSTRING = 60 + 1;
	const int MAX_CHAR = 8 + 1;
	extern int allocSize;

	struct Car {
	char licencePlate[MAX_CHAR];
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
