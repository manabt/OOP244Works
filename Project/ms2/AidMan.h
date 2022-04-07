/* ------------------------------------------------------
OOP244 NAA
Final Project milestone 2
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/03/22
-----------------------------------------------------------*/
/*----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------*/
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"

namespace sdds {
	class AidMan {
		char* m_filename;
		Menu m_menu;
		unsigned int menu()const;
		void deAllocate();
	public:
		AidMan();
		~AidMan();
		AidMan(const AidMan& source) = delete;
		AidMan& operator=(const AidMan& source) = delete;
		void run();
	};
}

#endif // !SDDS_AIDMAN_H