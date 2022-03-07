/* ------------------------------------------------------
OOP244 NAA
Workshop 6 part 1
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/03/06
-----------------------------------------------------------*/
//The code in this workshop is provided by my professor
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "Name.h"

using namespace std;
namespace sdds {
	void Name::setEmpty() {
		m_firstName = nullptr;
		m_lastName = nullptr;
		m_middleName = nullptr;
	}
	void Name::deAllocate() {
		delete[] m_firstName;
		m_firstName = nullptr;
		delete[] m_lastName;
		m_lastName = nullptr;
		delete[] m_middleName;
		m_middleName = nullptr;
	}
	Name::Name() {
		setEmpty();
	}
	Name::Name(const char* firstName) {
		if (!isEmpty(firstName)) {
			setFirst(firstName);
		}

	}
	Name::Name(const char* firstName, const char* lastName) {

		if (!isEmpty(firstName) && !isEmpty(lastName)) {
			setFirst(firstName);
			setLast(lastName);
		}
	}
	Name::Name(const char* firstName, const char* lastName, const char* middleName) {
		if (!isEmpty(firstName) && !isEmpty(lastName) && !isEmpty(middleName)) {
			set(firstName, lastName, middleName);
		}
	}
	// Copy constructor
	Name::Name(const Name& toCopyFrom) {
		if (toCopyFrom.m_middleName != nullptr && toCopyFrom.m_lastName != nullptr) {
			set(toCopyFrom.m_firstName, toCopyFrom.m_lastName, toCopyFrom.m_middleName);
		}
		else if (toCopyFrom.m_middleName == nullptr && toCopyFrom.m_lastName != nullptr) {
			setFirst(toCopyFrom.m_firstName);
			setLast(toCopyFrom.m_lastName);
		}
		else {
			setFirst(toCopyFrom.m_firstName);
		}
	}
	// Destructor
	Name::~Name() {
		deAllocate();
	}
	// Copy assignment
	Name& Name::operator=(const Name& toCopyFrom) {
		deAllocate();
		m_firstName = nullptr, m_lastName = nullptr, m_middleName = nullptr;
		if (toCopyFrom.m_middleName != nullptr && toCopyFrom.m_lastName != nullptr) {
			set(toCopyFrom.m_firstName, toCopyFrom.m_lastName, toCopyFrom.m_middleName);
		}
		else if (toCopyFrom.m_middleName == nullptr && toCopyFrom.m_lastName != nullptr) {
			setFirst(toCopyFrom.m_firstName);
			setLast(toCopyFrom.m_lastName);
		}
		else {
			set(toCopyFrom.m_firstName);
		}
		return *this;
	}
	Name& Name::set(const char* first, const char* last, const char* middle) {
		setFirst(first);
		setLast(last);
		setMiddle(middle);
		return *this;
	}
	Name& Name::setFirst(const char* first) {
		if (first != nullptr) {
			delete[] m_firstName;
			m_firstName = new char[strlen(first)+1];
			strcpy(m_firstName, first);
		}
		return *this;
	}

	Name& Name::setLast(const char* last) {
		if (last != nullptr) {
			delete[] m_lastName;
			m_lastName = new char[strlen(last ) + 1];
			strcpy(m_lastName, last);
		}
		return *this;
	}
	Name& Name::setMiddle(const char* middle) {
		if (middle != nullptr) {
			delete[] m_middleName;
			m_middleName = new char[strlen(middle ) + 1];
			strcpy(m_middleName, middle);
		}
		return *this;
	}
	Name& Name::setShort(bool state)const {
		m_short = true;
		return *this;
	}
	Name& Name::operator+=(const char* add) {
		bool done = false;
		for (int i = 0; i < strlen(add) && !done; i++)
		{
			if (isspace(add[i])) {
				setEmpty();
				done = true;
			}
		}
		if (!isEmpty(add)) {

			if (m_firstName == nullptr) {
				setFirst(add);
			}
			else if (m_middleName == nullptr) {
				setMiddle(add);
			}
			else if (m_lastName == nullptr) {
				setLast(add);
			}
			else {
				setEmpty();
			}
		}
		return *this;
	}
	bool Name::isEmpty(const char* name) const {
		bool state = true;
		if (name != nullptr) {
			for (int i = 0; state == true && name[i]; i++) {
				if (name[i] != ' ') state = false;
			}
		}
		return state;
	}
	std::istream& Name::read(std::istream& istr) {

		string name[3];
		deAllocate();
		//getline(istr, name, ' ');
		istr >> name[0];
		if (istr.peek() == ' ') {
			istr >> name[1];
		}
		if (istr.peek() == ' ') {
			istr >> name[2];
		}
		if (istr.peek() == '\n') {
			if (name[2]...) {
				set(first.c_str());
				set(middle.c_str());
			}
			else if (!middle.empty() && !last.empty()) {
				set(last.c_str());
				set(first.c_str());
				set(middle.c_str());
			}
		}
		return istr;
	}
	std::ostream& Name::display(std::ostream& ostr)const {
		if (m_firstName == nullptr) {
			ostr << "Bad Name";
		}
		else if (m_lastName == nullptr && m_middleName == nullptr) {
			ostr << m_firstName;
		}
		else if (m_lastName != nullptr && m_middleName == nullptr) {
			ostr << m_firstName << " " << m_lastName;
		}
		else if (m_firstName != nullptr && m_lastName != nullptr && m_middleName != nullptr)
		{ 
			if(m_short)
				ostr << m_firstName << " " << m_middleName[0] << ". " << m_lastName;
			else
				ostr << m_firstName << " " << m_middleName << " " << m_lastName;
		}
		return ostr;
	}
	Name::operator bool() const {
		return m_firstName != nullptr;
	}
	std::istream& operator>>(std::istream& istr, Name& RO) {
		return RO.read(istr);
	}
	std::ostream& operator<<(std::ostream& ostr, const Name& RO) {
		return RO.display(ostr);
	}
}