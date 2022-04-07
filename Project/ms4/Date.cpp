/* ------------------------------------------------------
OOP244 NAA
Final Project milestone 4
Name : Mana Babatabarsorkhi
Student ID: 117498212
Seneca Email: mbabatabarsorkhi@myseneca.ca
date: 2022/04/07
-----------------------------------------------------------*/
/*----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	bool sdds::Date::validate() {
		bool done = false;
		int currentYear;
		ut.getSystemDate(&currentYear);
		if (m_year < currentYear || m_year > maxYearValue) {
			m_state.set("Invalid year in date", 1);
		}
		else if (m_month < 1 || m_month > 12) {
			m_state.set("Invalid month in date", 2);
		}
		else if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)) {
			m_state.set("Invalid day in date", 3);
		}
		else {
			m_state.clear();
			done = true;
		}
		return done;
	}
	int sdds::Date::uniqDate()const {
		int date = m_year * 372 + m_month * 31 + m_day;
		return date;
	}
	Date::Date() {
		ut.getSystemDate(&m_year, &m_month, &m_day);
	}
	Date::Date(int year, int month, int day) {
		set(year, month, day);
	}
	Date& Date::set(int year, int month, int day) {
		m_year = year;
		m_month = month;
		m_day = day;
		return *this;
	}
	bool Date::operator==(const Date& date)const {
		return this->uniqDate() == date.uniqDate();
	}
	bool Date::operator!=(const Date& date)const {
		return !operator==(date);
	}
	bool Date::operator<(const Date& date)const {
		return this->uniqDate() < date.uniqDate();
	}
	bool Date::operator>(const Date& date)const {
		return this->uniqDate() > date.uniqDate();
	}
	bool Date::operator<=(const Date& date)const {
		return this->uniqDate() <= date.uniqDate();
	}
	bool Date::operator>=(const Date& date)const {
		return this->uniqDate() >= date.uniqDate();
	}
	const Status& Date::state() const {
		return m_state;
	}
	Date& Date::formatted(bool condition) {
		m_formatted = condition;
		return *this;
	}
	Date::operator bool() const {
		return m_state;
	}
	std::ostream& Date::write(std::ostream& os) const {
		if (m_formatted) {
			os << m_year << "/";
			os << setw(2);
			os.fill('0');
			os << m_month << "/" << m_day;
		}
		else {
			os << m_year - 2000;
			os << setw(2);
			os.fill('0');
			os << m_month << m_day;
		}
		return os;
	}
	std::istream& Date::read(std::istream& is) {
		m_state.clear();
		int value;
		is >> value;
		if (is.fail()) {
			m_state.set("Invalid date value");
			return is;
		}
		m_year = value / 10000;
		value %= 10000;
		if (m_year == 0) {
			ut.getSystemDate(&m_year);
			m_month = value / 100;
			m_day = value % 100;
		}
		else {
			m_year += 2000;
			m_month = value / 100;
			m_day = value % 100;
		}
		if (!validate()) {
			is.setstate(ios::badbit);
		}
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const Date& RO) {
		return RO.write(os);
	}
	std::istream& operator>>(std::istream& is, Date& RO) {
		return RO.read(is);
	}
}


