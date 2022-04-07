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
#include <iomanip>
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds {
	void Rectangle::setEmpty() {
		m_width = 0;
		m_height = 0;
	}
	bool Rectangle::isEmpty()const {
		return (m_width == 0 || m_height == 0);
	}
	sdds::Rectangle::Rectangle(): LblShape(){
		setEmpty();
	}
	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {
		m_width = width;
		m_height = height;
		//const char* lbl = LblShape::label();
		unsigned int length = strlen(LblShape::label() + 2);
		if (m_height < 3 || m_width < length){
			setEmpty();
		}
	}
	void Rectangle::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_width;
		if (istr.peek() == ',') {
			//istr.ignore(1000, ',');
			//istr.get();
			istr.ignore();
		}
		istr >> m_height;
		istr.ignore(1000, '\n');
	}
	void Rectangle::draw(std::ostream& ostr) const {
		int width = m_width - 2;
		int height = m_height - 3;
		if (!isEmpty()) {
			// 1st line
			ostr << "+";
			for (int i = 0; i < width; i++) {
				ostr << "-";
			}
			ostr << "+" << endl;
			// 2nd line
			ostr << "|";
			ostr << setw(width);
			ostr.setf(ios::left);
			ostr << label();
			ostr.unsetf(ios::left);
			ostr << "|" << endl;
			// next two lines
			for (int i = 0; i < height; i++) {
				ostr << "| ";
				ostr << setw(width);
				ostr << "|" << endl;
			}
			// last line
			ostr << "+";
			for (int i = 0; i < width; i++) {
				ostr << "-";
			}
			ostr << "+";
		}
	}
}