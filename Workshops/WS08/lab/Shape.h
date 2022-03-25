/* ------------------------------------------------------
OOP244 NAA
Workshop 8 part 1
Name : Mana Babatabarsorkhi
Student ID : 117498212
Seneca Email : mbabatabarsorkhi@myseneca.ca
date : 2022 / 03 / 22
----------------------------------------------------------- */
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream&) const = 0;// must be void
		virtual void getSpecs(std::istream&) = 0; // must be void
		virtual ~Shape();
	};
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
	std::istream& operator>>(std::istream& istr, Shape& shape);
}
#endif 

