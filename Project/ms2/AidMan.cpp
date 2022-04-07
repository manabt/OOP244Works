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
#include <iostream>
#include "AidMan.h"
#include "Date.h"

using namespace std;
namespace sdds {
	char content[200] = "1- List Items\n"
		"2- Add Item\n"
		"3- Remove Item\n"
		"4- Update Quantity\n"
		"5- Sort\n"
		"6- Ship Items\n"
		"7- New/Open Aid Database\n"
		"---------------------------------\n";
	unsigned int AidMan::menu() const {
		cout << "Aid Management System Version 0.1" << endl;
		cout << "Date: " << Date() << endl;
		if (m_filename != nullptr) {
			cout << "Data file: " << m_filename << endl;
		}
		else {
			cout << "Data file: No file" << endl;
		}
		cout << "---------------------------------" << endl;
		unsigned int num = m_menu.run();
		return num;
	}
	void AidMan::deAllocate() {
		delete[] m_filename;
		m_filename = nullptr;
	}
	AidMan::AidMan() : m_filename{ nullptr },m_menu{ 7,content }{
	}
	AidMan::~AidMan() {
		deAllocate();
	}
	void AidMan::run() {
		int num;
		bool done = false;
		do {
			num = menu();
			switch (num) {
			case 0:
				done = true;
				cout << "Exiting Program!" << endl;
				break;
			case 1:
				cout << "\n****List Items****\n" << endl;
				break;
			case 2:
				cout << "\n****Add Item****\n" << endl;
				
				break;
			case 3:
				cout << "\n****Remove Item****\n" << endl;
				break;
			case 4:
				cout << "\n****Update Quantity****\n" << endl;
				break;
			case 5:
				cout << "\n****Sort****\n" << endl;
				break;
			case 6:
				cout << "\n****Ship Items****\n" << endl;
				break;
			case 7:
				cout << "\n****New/Open Aid Database****\n" << endl;
				break;
			default:
				break;
			}
		} while (!done);
	}
}