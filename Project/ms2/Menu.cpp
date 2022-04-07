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
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	Menu::Menu(unsigned int num, const char* list) {
		m_menuList = nullptr;
		if (num <= maxOptions && list != nullptr) {
			m_numOptions = num;
			ut.alocpy(m_menuList, list);
		}
		else {
			deAllocate();
			m_numOptions = 0;
		}
	}
	Menu::~Menu() {
		deAllocate();
	}
	void Menu::deAllocate() {
		delete[] m_menuList;
		m_menuList = nullptr;
	}
	unsigned int Menu::run()const {
		int num;
		cout << m_menuList;
		cout << "0- Exit" << endl;
		cout << "> ";
		num = ut.getint(0, m_numOptions);
		return num;
	}
}

