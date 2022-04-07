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
#include "Utils.h"
#include "Status.h"
using namespace std;

namespace sdds {
	Status& Status::clear() {
		delete[] m_status;
		m_status = nullptr;
		return *this;
	}
	Status::Status(const char* status) {
		m_statusCode = 0;
		if (status) {
			set(status, 0);
		}
	}
	Status::Status(const Status& toCopyFrom) {
		set(toCopyFrom.m_status, toCopyFrom.m_statusCode);
	}
	Status::~Status() {
		clear();
	}
	Status& Status::operator=(const Status& toCopyFrom) {
		if (this != &toCopyFrom) {
			clear();
			set(toCopyFrom.m_status, toCopyFrom.m_statusCode);
		}
		return *this;
	}
	Status& Status::set(const char* status, int code) {
		if (status) {
			ut.alocpy(m_status, status);
		}
		m_statusCode = code;
		return *this;
	}
	Status& Status::operator=(const char* status) {
		ut.alocpy(m_status, status);
		return *this;
	}
	Status& Status::operator=(int code) {
		m_statusCode = code;
		return *this;
	}
	Status::operator const char* () const {
		return m_status;
	}
	Status::operator const int() const {
		return m_statusCode;
	}
	Status::operator bool() const {
		return m_status == nullptr;
	}
	std::ostream& Status::display(ostream& ostr) const {
		if (this) {
			if (m_statusCode != 0) {
				ostr << "ERR#" << m_statusCode << ": ";
			}
			ostr << m_status;
		}
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Status& RO) {
		return RO.display(ostr);
	}
}