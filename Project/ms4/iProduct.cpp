/* ------------------------------------------------------
OOP244 NAA
Final Project milestone 4
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/04/04
-----------------------------------------------------------*/
/*----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------*/
#include <iostream>
#include "iProduct.h"

namespace sdds {
	iProduct::~iProduct() {}
	std::ostream& operator<<(std::ostream& ostr, const iProduct& iPrd) {
		iPrd.display(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, iProduct& iPrd) {
		iPrd.read(istr);
		return istr;
	}
}