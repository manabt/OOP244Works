/* ------------------------------------------------------
OOP244 NAA
Workshop 7 part 1
Name : Mana Babatabarsorkhi
Student ID : 117498212
Seneca Email : mbabatabarsorkhi@myseneca.ca
date : 2022 / 03 / 17
----------------------------------------------------------- */
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"

namespace sdds {
	class Pack : public Container {
		int m_unitSize;
	public:
		Pack(const char* content, int maxSize, int unitSize = 330, int numUnits = 0);
		int operator+=(const int val);
		int operator-=(const int val); 
		int unit()const;
		int noOfUnits()const;
		int size()const;
		void clear(int size, int unitSize, const char* content);
		std::ostream& print(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
	std::istream& operator>>(std::istream& istr, Pack& RO);
	std::ostream& operator<<(std::ostream& ostr, const Pack& RO);
}
#endif // !SDDS_PACK_H