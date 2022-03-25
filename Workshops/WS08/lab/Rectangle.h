/* ------------------------------------------------------
OOP244 NAA
Workshop 8 part 1
Name : Mana Babatabarsorkhi
Student ID : 117498212
Seneca Email : mbabatabarsorkhi@myseneca.ca
date : 2022 / 03 / 22
----------------------------------------------------------- */
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"

namespace sdds {

	class Rectangle : public LblShape {
		unsigned int m_width;
		unsigned int m_height;
		void setEmpty();
		bool isEmpty()const;
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr) const;
	};
}
#endif 