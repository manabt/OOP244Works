/* ------------------------------------------------------
OOP244 NAA
Workshop 8 part 1
Name : Mana Babatabarsorkhi
Student ID : 117498212
Seneca Email : mbabatabarsorkhi@myseneca.ca
date : 2022 / 03 / 22
----------------------------------------------------------- */
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "LblShape.h"

using namespace std;
namespace sdds {
	LblShape& LblShape::set(const char* lbl) {
		m_label = new char[strlen(lbl) + 1];
		strcpy(m_label, lbl);
		return *this;
	}
	const char* LblShape::label() const {
		return m_label;
	}
	LblShape::LblShape(){}
	LblShape::LblShape(const char* label) {
		if (label) {
			set(label);
		}
	}
	LblShape::~LblShape() {
		delete[] m_label;
	}
	void LblShape::getSpecs(std::istream& istr) {
		string str;
		getline(istr, str, ',');
		if (istr) { // if istr didn't fail :
			delete[] m_label;
			set(str.c_str());
		}
	}
}