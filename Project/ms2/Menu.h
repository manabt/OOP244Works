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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {
	const int maxOptions = 15;
	class Menu {
		char* m_menuList;
		unsigned int m_numOptions = 3;
		void deAllocate();
	public:
		Menu(unsigned int num, const char* list);
		Menu(const Menu& source) = delete;
		Menu& operator=(const Menu& source) = delete;
		~Menu();
		unsigned int run()const;
	};
}

#endif // !SDDS_MENU_H