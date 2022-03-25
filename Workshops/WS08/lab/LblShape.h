/* ------------------------------------------------------
OOP244 NAA
Workshop 8 part 1
Name : Mana Babatabarsorkhi
Student ID : 117498212
Seneca Email : mbabatabarsorkhi@myseneca.ca
date : 2022 / 03 / 22
----------------------------------------------------------- */
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include <iostream>
#include "Shape.h"

namespace sdds {

	class LblShape : public Shape{
		char* m_label{};
		LblShape& set(const char* lbl);
	protected:
		const char* label()const;
	public:
		LblShape();
		LblShape(const char* label);
		virtual ~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		void getSpecs(std::istream& istr);
	};
}

#endif 
