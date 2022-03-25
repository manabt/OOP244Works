/* ------------------------------------------------------
OOP244 NAA
Workshop 8 part 1
Name : Mana Babatabarsorkhi
Student ID : 117498212
Seneca Email : mbabatabarsorkhi@myseneca.ca
date : 2022 / 03 / 22
----------------------------------------------------------- */
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds {
	Line::Line(): LblShape() {
		m_length = 0;
	}
	Line::Line(const char* label, int length): LblShape(label) {
		m_length = length;
	}
	void Line::getSpecs(std::istream& istr) {
		int num;
		LblShape::getSpecs(istr);
		istr >> num;
		istr.ignore(1000, '\n');
		if (istr) {
			m_length = num;
		}
	}
	void Line::draw(std::ostream& ostr) const {
		if (m_length > 0 && label() != nullptr) {
			cout << label() << endl;
			for (int i = 0; i < m_length; i++) {
				cout << "=";
			}
		}
	}
}