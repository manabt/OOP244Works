/* ------------------------------------------------------
OOP244 NAA
Final Project milestone 4
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/04/07
-----------------------------------------------------------*/
/*----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------*/
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include <iostream>
#include "Item.h"
#include "Date.h"

/// when you reading from the file for ms5, all you need to do is to peek the first
//  character of the record and if it is 1,2,3 it is perishable and if not, create a 
//  regular item.
namespace sdds {
	class Perishable : public Item {
		Date m_expiry{};
		char* m_handling{}; // could be null & still valid
	public:
		Perishable() = default;
		Perishable(const Perishable& source);
		Perishable& operator=(const Perishable& source);
		virtual ~Perishable();
		const Date& expiry()const;
		int readSku(std::istream& istr);
		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
}
#endif // !SDDS_PERISHABLE_H
