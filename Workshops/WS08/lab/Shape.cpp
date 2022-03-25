/* ------------------------------------------------------
OOP244 NAA
Workshop 8 part 1
Name : Mana Babatabarsorkhi
Student ID : 117498212
Seneca Email : mbabatabarsorkhi@myseneca.ca
date : 2022 / 03 / 22
----------------------------------------------------------- */
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#include "Shape.h"
using namespace std;

namespace sdds {
	sdds::Shape::~Shape() {}
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape) {
		shape.draw(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Shape& shape) {
		shape.getSpecs(istr);
		return istr;
	}
}
