/* ------------------------------------------------------
OOP244 NAA
Workshop 3 part 1
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/02/02
-----------------------------------------------------------*/
#ifndef SDDS_TRAIN_H_
#define SDDS_TRAIN_H_

namespace sdds {
	const int MAX_NAME_LENGTH = 20 + 1;
	const int MAX_PEOPLE = 1000 + 1;
	const int MAX_SPEED = 320 + 1;

	class Train {
		// Member Varaibles: 
		char m_trainName[MAX_NAME_LENGTH];
		int m_numPeople;
		double m_speed;
		// Memeber functions:
		void setSafeEmpty(); // Modifier
	public:
		void set(const char* name, int num, double speed); // Modifier
		// Queries:
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;
	};
}
#endif // !SDDS_TRAIN_H

